def main():
    names = []
    try:
        user_input = int(input("How many names would you like to enter: "))
        if(user_input < 1):
            print("invalid input")
            main()

        counter = 0
        while(counter < user_input):
            name = input("Enter a name: ")
            names.append(name)
            counter += 1
    except ValueError:
        print("Invalid input")

    num1 = []
    num2 = []
    try:
        user_input = int(input("How many numbers would you like in the first list: "))
        if(user_input < 1):
            print("invalid input")
            main()

        counter = 0
        while(counter < user_input):
            num = int(input("Enter numbers: "))
            num1.append(num)
            counter += 1
    except ValueError:
        print("Invalid input")

    try:
        user_input = int(input("How many numbers would you like in the second list: "))
        if(user_input < 1):
            print("invalid input")
            main()

        counter = 0
        while(counter < user_input):
            num = int(input("Enter numbers: "))
            num2.append(num)
            counter += 1
    except ValueError:
        print("Invalid input")

    print("Occurence of each letter: ", same_letters(names))
    print("Same length: ", same_length(num1,num2))
    print("The sum of the first list is: ", sum(num1))
    print("The average of the second list is: ", average(num2))
    print("Different sum: ", sum_2(num1, num2))
    print("Common numbers: ", common_num(num1,num2))

def same_letters(names):
    temp = []

    for i in names:
        for j in i:
            temp.append(j)

    return [[x,temp.count(x)] for x in set(temp)]


#return true if lists are the same length
def same_length(num_list, num2_list):
    length1 = len(num_list)
    length2 = len(num2_list)

    if(length1 == length2):
        return True
    else:
        return False

#returns the sum of a list
def sum(num_list):
    x = 0

    for i in num_list:
        x += i

    return x

#returns the average of a list
def average(num2_list):
    x = 0

    for i in num2_list:
        x += i

    return (x/len(num2_list))

#returns true if the average of one list is different from the other
def sum_2(num_list, num2_list):
    x = 0
    y = 0

    for i in num_list:
        x += i

    for j in num2_list:
        y += j
    
    x = x/len(num_list)
    y = y/len(num2_list)

    if((x > y) or (x < y)):
        return True
    else:
        return False

#returns the common numbers of both lists
def common_num(num_list, num2_list):
    return list(set(num_list) & set(num2_list))

main()