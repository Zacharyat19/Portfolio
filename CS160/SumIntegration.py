def main():
	user_input = int(input("Which function would you like to use:\n1) 10x^2\n2) 2x^2 - 5\n3) x + 20\n"))
	if(user_input == 1):
		sum_1()
	elif(user_input == 2):
		sum_2()
	elif(user_input == 3):
		sum_3()

def sum_1():
	#ask for upper and lower limits
	lower = int(input("What is the lower limit: \n"))
	upper = int(input("What is the upper limit: \n"))
	
	counter = 0
	x = 0
	y = 0
	
	while( lower <= upper):
		x = lower**2
		y = 10 * x
		
		counter = counter + y
		lower += 1

	print("The sum is", counter)

def sum_2():
	lower = int(input("What is the lower limit: \n"))
	upper = int(input("What is the upper limit: \n"))

	counter = 0
	x = 0
	y = 0
	z = 0

	while(lower <= upper):
		x = lower**2
		y = 2 * x
		z = y - 5
	
		counter = counter + z
		lower += 1

	print("The sum is", counter)	
	
def sum_3():
	lower = int(input("What is the lower limit: \n"))
	upper = int(input("What is the lower limit: \n"))

	counter = 0
	x = 0
	
	while(lower <= upper):
		x = lower +20
		counter = counter + x
		lower += 1

	print("The sum is", counter)

def f(x):
    return 10*(x**2)

def integration_1():
    a = int(input("What is the starting interval: \n"))
    b = int(input("What is the ending interval: \n"))
    n = int(input("How many rectangles: \n"))

    area = 0
    width = (b-a)/n
    height = 
    for i in range(n):
        are += width * f(x)
        x += width
    print("Area: ", area)

main()	