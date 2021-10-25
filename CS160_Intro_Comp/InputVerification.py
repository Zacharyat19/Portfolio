def main(): 
    print(is_int("-150"))
    print(is_int("a"))
    print(is_floating_pt("5.0"))
    print(is_floating_pt("4.7."))
    print(is_email("123123@something.com"))
    print(is_email("something.com@me"))
    print(is_IP("76.240.249.145"))
    print(is_IP("93.2422.244.902"))

def is_int(num):
    for i in num:
        if(i >= "0" and i <= "9"):
            return  True
        elif(i == "-"):
            if(i >= "0" and i <= "9"):
                return True
        else:
            return False

def is_floating_pt(num):
    x = -1
    for i in num:
        if(i == '.' and x == -1):
            x = i
        elif(i == '.' and x != -1):
            return False
        if(i >= 'a' and i <= 'z') or (i >= 'A' and i <= 'Z'):
            return False
    return True

def is_email(email):
    if(email.find("@") < email.find(".com")):
        return True
    else:
            return False

def is_IP(num):
    temp = []

    for i in num:
        temp.append(i)
    
    if(temp[2] == "." and temp[6] == "." and temp[10] == "."):
        temp.remove(".")
        for i in temp:
            if(i >= "0" and i <= "9"):
                return True
    else:
        return False

main()