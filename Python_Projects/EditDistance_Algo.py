import sys

def file_contents_letters(file_name):
    """
    Takes a file name as input and returns a string consisting of the file's contents
    with all non-letter characters removed.
    
    Parameters:
        file_name: The name of the file.
    
    Returns:
        A string with the contents of <file_name> but with all non-letter characters removed.
    """

    f = open(file_name, "r")
    file_contents = f.read()
    f.close()
    return "".join([c for c in file_contents if c.isalpha()])
    
def edit_distance(s1, s2):
    """
    Computes the edit distance between two strings, s1 and s2.
    
    Parameters:
        s1: The first string.
        s2: The second string.
    
    Returns:
        The edit distance between s1 and s2.
    """

    #Get lengths of input strings
    n = len(s1)
    m = len(s2)

    #Make table
    Edit = [[0 for i in range(m + 1)] for i in range(n + 1)]

    #Loop through and add values
    for i in range(n + 1):
        for j in range(m + 1):
            #Fill first row values
            if i == 0:
                Edit[i][j] = j
            #Fill column values
            elif j == 0:
                Edit[i][j] = i
            #If characters are the same get the previous operation
            elif s1[i - 1] == s2[j - 1]:
                Edit[i][j] = Edit[i - 1][j - 1]
            #If characters are not the same, find minimum operation value
            else:
                Edit[i][j] = 1 + min(Edit[i][j - 1], Edit[i - 1][j], Edit[i - 1][j - 1])

    return Edit[n][m]
    
def longest_common_subsequence(s1, s2):
    """
    Computes the length of the longest common subsequence between two strings, s1 and s2.
    
    Parameters:
        s1: The first string.
        s2: The second string.
    
    Returns:
        The length of the longest common subsequence between s1 and s2.
    """
    #Get string lengths
    n = len(s1)
    m = len(s2)

    #Make table
    Edit = [[0 for x in range(m + 1)] for x in range(n + 1)]

    #Loop through and add values
    for i in range(n + 1):
        for j in range(m + 1):
            #Fill the first row and column with 0's
            if i == 0 or j == 0:
                Edit[i][j] = 0
            #If the characters are the same, fill the current index by adding one to its diagonal element
            elif s1[i - 1] == s2[j - 1]:
                Edit[i][j] = 1 + Edit[i - 1][j - 1]
            #If characters are not the same, take the max of verticle or adjacent index
            else:
                Edit[i][j] = max(Edit[i - 1][j], Edit[i][j - 1])

    return Edit[n][m], Edit

#Extra Credit, probably takes a million years and spits out an absurd string for covid
def print_longest_common_subsequence(s1, s2, Edit):
    n = len(s1)
    m = len(s2)
    k = Edit[n][m]

    #Make array of empty strings
    LCS = [""] * (k + 1)

    i = n
    j = m
    while i > 0 and j > 0:

        #If the characters are the same, append to the end of the array
        if s1[i - 1] == s2[j - 1]:
            LCS[k - 1] = s1[i - 1]
            i -= 1
            j -= 1
            k -= 1
        #Move through the matrix to find same characters
        elif Edit[i - 1][j] > Edit[i][j - 1]:
            i -= 1
        else:
            j -= 1
            
    #Join strings togethor        
    print("".join(LCS))
    return None

s1 = file_contents_letters(sys.argv[1])
s2 = file_contents_letters(sys.argv[2])
d = edit_distance(s1, s2)
k, Edit = longest_common_subsequence(s1, s2)
print(d, k)
print_longest_common_subsequence(s1, s2, Edit)