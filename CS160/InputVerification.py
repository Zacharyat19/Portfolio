def main(): 
    print(is_int("123"))
    print(is_floating_pt("0.123"))

def is_int(num):
    for i in num:
        if(not(i >= "0" and i <= "9")):
            return False
        else:
            return True

def is_floating_pt(num):
    for i in num:
        if(i == "." and i >= "0" and i <= "9"):
            return True
        else:
            return False


main()