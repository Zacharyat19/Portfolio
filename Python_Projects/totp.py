import sys
import qrcode
import base64
import hmac
import time
import struct
import hashlib
import secrets

#Algorithm variables
X = 30
T0 = 0

def make_key():
    key = "".join([secrets.choice("ABCDEFGHIJKLMNOPQRSTUVWXYZ") for i in range(0,16)])
    return key

def make_qr():
    #secret = "HelloWorld"
    secret = make_key()
    secret = base64.b32encode(secret.encode("UTF-8")).decode('UTF-8')
    secret = secret[0:16]
    
    uri = "otpauth://totp/Zacharyat19:test@google.com?secret=" + secret + "&issuer=Zacharyat19"

    qr = qrcode.make(uri)
    qr.save("qrcode.jpg")

    x = input("Would you like to protect your key with a password? [y/n]: ")
    if x == "y":
        file = open("secret.txt", "w")
        file.write("PROTECTED\n")
        file.write(secret)
        file.close()
    elif x == "n":
        file = open("secret.txt", "w") 
        file.write(secret)
        file.close()


def get_time():
    return (int(time.time()) - T0) // X

#https://datatracker.ietf.org/doc/html/rfc4226
#https://datatracker.ietf.org/doc/html/rfc6238#section-5
#https://datatracker.ietf.org/doc/html/rfc4226#section-5.3 
#https://www.geeksforgeeks.org/struct-module-python/
def OTP(code):
    T = get_time()

    s = base64.b32decode(code)
    time = struct.pack(">Q", T)
    h = hmac.new(s, time, hashlib.sha1).digest()

    off = h[len(h) - 1] & 0xf

    binary = ((h[off] & 0x7f) << 24) \
        |((h[off + 1] & 0xff) << 16) \
        |((h[off + 2] & 0xff) << 8) \
        |(h[off + 3] & 0xff)

    passcode = binary % (10**6)
    #passcode = (binary % (1000000))

    return passcode

def main():
    command = sys.argv[1]

    if command == "--generate-qr":
        make_qr()
        print("qr code saved to qrcode.jpg\n")
    elif command == "--get-otp":
        file = open("secret.txt", 'r')
        line = next(file)

        if line.strip() == "PROTECTED":
            x = input("Key is password protected, please enter the password: ")
            if x.strip() != "THISISASUPERSECRET":
                print("Incorrect password, terminating")
                exit()

            print("Password correct, starting TOTP\n")
            code = next(file)
            code.strip()
            file.close()

            prev = None
            while (1):
                totp = OTP(code)
                
                if totp != prev:
                    prev = totp
                    print("Passcode " + str(totp) + " valid for 30 seconds")
        else:
            print("Starting TOTP\n")
            code = line.strip()
            file.close()

            prev = None
            while (1):
                totp = OTP(code)
                
                if totp != prev:
                    prev = totp
                    print("Passcode " + str(totp) + " valid for 30 seconds")

    else :
        print("Invalid command\n")
        print("Valid commands include --get-otp and --get-otp\n")
        return

if __name__ == '__main__':
    main()