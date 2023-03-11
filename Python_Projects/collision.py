import random
import string
from cryptography.hazmat.primitives import hashes

def main():
    data = b'This is to be hashed'
    strong_str = ''.join(random.choice(string.ascii_letters)for i in range(6))
    list = []
    weak_count = 0
    strong_count = 0
    temp = None

    digest = hashes.Hash(hashes.SHA256())
    digest.update(data)
    data = digest.finalize().hex()[0:6]

    print("\nPerforming weak-collision test")
    while True:
        digest2 = hashes.Hash(hashes.SHA256())
        weak_str = ''.join(random.choice(string.ascii_letters)for i in range(6))
        digest2.update(weak_str.encode())
        x = digest2.finalize().hex()[0:6]

        if(x == data):
            print("Weak finished, took " + str(weak_count) + " cycles")
            #temp = weak_str
            break
        else:
            weak_count += 1

    #print('Collision with string "This is to be hashed" and ' + temp + "\n")
    print("\nPerforming strong-collision test")

    digest3 = hashes.Hash(hashes.SHA256())
    digest3.update(strong_str.encode())
    x = digest3.finalize().hex()[0:6]
    list.append(x)

    while True:
        str1 = ''.join(random.choice(string.ascii_letters)for i in range(6))
        if(str1 == strong_str):
            continue

        digest4 = hashes.Hash(hashes.SHA256())
        digest4.update(str1.encode())
        y = digest4.finalize().hex()[0:6]

        if y in list:
            print("strong finished, took " + str(strong_count) + " cycles")
            #temp = str1
            break
        else:
            list.append(y)
            strong_count += 1

    #print("Collision with string " + strong_str + " and " + temp + "\n")

main()