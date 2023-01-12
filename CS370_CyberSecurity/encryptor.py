import sys
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad

def encryptor(key, plaintext):
    if len(key) > 16:
        return None

    key += " "*(16 - len(key))
    key = key[:16]
    
    new_key = key.encode()
    new_plaintext = plaintext.encode()
    iv = bytes.fromhex('00000000000000000000000000000000')

    cipher = AES.new(new_key, AES.MODE_CBC, iv = iv)
    cipher_text = cipher.encrypt(pad(new_plaintext, AES.block_size))

    return cipher_text.hex()

def main():
    key_file = sys.argv[1]
    input_str = sys.argv[2:]
    text = ' '.join(input_str)
    cipher_text = "8d20e5056a8d24d0462ce74e4904c1b513e10d1df4a2ef2ad4540fae1ca0aaf9"
    found = False

    print("Your plaintext is  " + text)
    print("Your ciphertext is " + cipher_text)

    file = open(key_file, 'r')

    for line in file:
        x = line.strip()
        gen_cipher = encryptor(x, text)
        if gen_cipher == None:
            continue
        elif gen_cipher == cipher_text:
            found = True
            print("The key was " + line)
            break

    if not found:
        print("Key could not be found in key file")

    file.close()

main()