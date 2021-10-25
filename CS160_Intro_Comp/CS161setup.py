import math

def main():
    x = []
    y = []

    counter = 0
    while(counter < 4):
        user_input = int(input("Enter a number for x: "))
        x.append(user_input)
        counter += 1

    counter2 = 0
    while(counter2 < 4):
        user_input = int(input("Enter a number for y: "))
        y.append(user_input)
        counter2 += 1

    first = x[0] + y[0]
    second = x[1] + y[1]
    third = x[2] + y[2]
    fourth = x[3] + y[3]

    z = [first,second,third,fourth]
    
    x = 0
    for i in z:
        x += i
    x = math.sqrt(x)
    print("The squre root of the sum is: ", x)
    print(z[4])
    
main()