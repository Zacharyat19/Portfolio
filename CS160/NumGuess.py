import random

def main():
    numbers = []

    random.seed()
    for i in range(5):
        numbers.append(random.randint(1,100))
    print(numbers[0])

    user_input = int(input("How many times would you like to guess: "))

    counter = 0
    while(counter < user_input):
        choice = int(input("Make a guess: "))

        for i in numbers:
            if(i == choice):
                print("You got one!")
                return
            else:
                print("Try again.")

        counter += 1

    print("The numbers were: ", numbers)
    
main()