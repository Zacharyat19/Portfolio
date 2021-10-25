import heapq
from collections import deque

class Node:
    def __init__(self, count, left = None, right = None):
        self.count = count
        self.left = left
        self.right = right
        self.code = ""

    def is_leaf(self):
        return False

    def __lt__(self, other):
        return self.count < other.count

    def __eq__(self, other):
        return self.count == other.count

class LeafNode(Node):
    def __init__(self, symbol, count):
        super().__init__(count)
        self.symbol = symbol

    def is_leaf(self):
        return True
    
class HuffmanCode:
    def __init__(self, F):
        self.C = dict()
        self.T = None
        self.F = F
        self.make_tree()
        self.make_table(self.T)

    def make_tree(self):
        Q = []
        for i, j in self.F.items():
            n = LeafNode(i, j)
            heapq.heappush(Q, n)

        while len(Q) > 1:
            temp1 = heapq.heappop(Q)
            temp2 = heapq.heappop(Q)
            temp1.code = "0"
            temp2.code = "1"
            n = temp1.count + temp2.count
            u = Node(n, temp1, temp2)
            heapq.heappush(Q, u)

        self.T = heapq.heappop(Q)
        return

    def make_table(self, node, val = ""):
        Val = val + str(node.code)

        if(node.left):
            self.make_table(node.left, Val)
        if(node.right):
            self.make_table(node.right, Val)

        if(not node.left and not node.right):
            self.C[node.symbol] = Val
        
        return

    def encode(self, m):
        """        
        Uses self.C to encode a binary message.

        Parameters:            
            m: A plaintext message.

        Returns:            
            The binary encoding of the plaintext message obtained using self.C.        
        """    

        s = ""    
        for i in m:
            if i in self.C:
                s += str(self.C[i])

        return s

    def decode(self, c):        
        """        
        Uses self.T to decode a binary message c = encode(m)..            
        
        Parameters:            
            c: A message encoded in binary using self.encode.        
            
        Returns:            
            The original plaintext message m decoded using self.T.        
        """        
        s = ""
        node = self.T
        for i in c:
            if i == "0":
                node = node.left
            elif i == "1":
                node = node.right
            if node.is_leaf():
                s += str(node.symbol)
                node = self.T
    
        return s

def get_frequencies(s):    
    """    
    Computes a frequency table for the input string "s".
    
    Parameters:        
        s: A string.  

    Returns:        
        A frequency table F such that F[c] = (# of occurrences of c in s).    
    """    
    F = dict()    
    for char in s:        
        if char in F:            
            F[char] += 1        
        else:            
            F[char] = 1    
    return F

def main():
    n = input("Enter input string: ")
    F = get_frequencies(n)
    H = HuffmanCode(F)
    
    m = input("Enter a message to encode ")
    new_m = H.encode(m)
    print(new_m)

    d = input("Enter a message to decode ")
    new_d = H.decode(d)
    print(new_d)

main()