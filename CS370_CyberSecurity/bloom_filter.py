import sys
import hashlib 

bit_size = 16000000
bit_vector_3 = [0] * bit_size
bit_vector_5 = [0] * bit_size

#https://stackoverflow.com/questions/209513/convert-hex-string-to-int-in-python
#Logic https://llimllib.github.io/bloomfilter-tutorial/
def make_bloom_filter(input):
    try:
        input = input.encode('utf-8')
    except:
        return
        
    hash1 = int(hashlib.md5(input).hexdigest(), 16) % bit_size
    hash2 = int(hashlib.sha224(input).hexdigest(), 16) % bit_size
    hash3 = int(hashlib.sha256(input).hexdigest(), 16) % bit_size
    hash4 = int(hashlib.sha384(input).hexdigest(), 16) % bit_size
    hash5 = int(hashlib.sha512(input).hexdigest(), 16) % bit_size
    
    bit_vector_3[hash1] = 1
    bit_vector_5[hash1] = 1

    bit_vector_3[hash2] = 1
    bit_vector_5[hash2] = 1

    bit_vector_3[hash3] = 1
    bit_vector_5[hash3] = 1

    bit_vector_5[hash4] = 1

    bit_vector_5[hash5] = 1

def test_3(input):
    input = input.encode('utf-8')
    hash1 = int(hashlib.md5(input).hexdigest(), 16) % bit_size
    hash2 = int(hashlib.sha224(input).hexdigest(), 16) % bit_size
    hash3 = int(hashlib.sha256(input).hexdigest(), 16) % bit_size

    if bit_vector_3[hash1] == 1 and bit_vector_3[hash2] == 1 and bit_vector_3[hash3] == 1:
        output = "maybe"
    else:
        output = "No"

    file = open('output3.txt', 'a')

    line = input.strip() + " " + output + "\n"
    file.write(line)
    file.close()

def test_5(input):
    input = input.encode('utf-8')
    hash1 = int(hashlib.md5(input).hexdigest(), 16) % bit_size
    hash2 = int(hashlib.sha224(input).hexdigest(), 16) % bit_size
    hash3 = int(hashlib.sha256(input).hexdigest(), 16) % bit_size
    hash4 = int(hashlib.sha384(input).hexdigest(), 16) % bit_size
    hash5 = int(hashlib.sha512(input).hexdigest(), 16) % bit_size

    if bit_vector_5[hash1] == 1 and bit_vector_5[hash2] == 1 and bit_vector_5[hash3] == 1 and bit_vector_5[hash4] == 1 and bit_vector_5[hash5] == 1:
        output = "maybe"
    else:
        output = "No"

    file = open('output5.txt', 'a')

    line = input.strip() + " " + output + "\n"
    file.write(line)
    file.close()

def main():
    dictionary2 = sys.argv[1]
    sample = sys.argv[2]

    print("Building bloom filters")

    file = open(dictionary2)
    for line in file:
        line.strip()
        make_bloom_filter(line)

    print("Bloom filters built\n")
    file.close()

    print("Passing data into 3 hash filter")
    file = open(sample, 'r')
    num_pass = next(file)
    out = open('output3.txt', 'w')
    out.write(num_pass)
    out.close()

    for line in file:
        line.strip()
        test_3(line)

    print("Output printed to output3.txt\n")
    file.close()

    print("Passing data into 5 hash filter")
    file = open(sample, 'r')
    num_pass = next(file)
    out2 = open('output5.txt', 'w')
    out2.write(num_pass)
    out2.close()

    for line in file:
        line.strip()
        test_5(line)

    print("Output printed to output5.txt\n")
    file.close()

if __name__ == '__main__':
    main()