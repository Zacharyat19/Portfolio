def main():
	user_input = int(input("Which function would you like to use:\n1) 10x^2\n2) 2x^2 - 5\n3) x + 20\n"))
	if(user_input == 1):
		user_input = int(input("1) Summation\n2) Integration \n"))
		if(user_input == 1):
			sum_1()
		elif(user_input == 2):
			integration1()
	elif(user_input == 2):
		user_input = int(input("1) Summation\n2) Integration \n"))
		if(user_input == 1):
			sum_2()
		elif(user_input == 2):
			integration2()
	elif(user_input == 3):
		user_input = int(input("1) Summation\n2) Integration \n"))
		if(user_input == 1):
			sum_3()
		elif(user_input == 2):
			integration3()

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

#Start integral section
def f(x):
    return 10*(x**2)

def f2(x):
	return (2*(x**2)) - 5

def f3(x):
	return x + 20

def integration1():
	choice = int(input("1) Rectangle \n2) Trapezoid\n"))

	if(choice == 1):
		n = int(input("How many rectangles: "))
		a = int(input("Enter a: "))
		b = int(input("Enter b: "))

		area = 0
		x = a 
		width = (b-a)/n

		for i in range(n):
			area += width * f(x)
			x += width
		print("Area: ", area)
	elif(choice == 2):
		n = int(input("How many rectangles: "))
		a = int(input("Enter a: "))
		b = int(input("Enter b: "))

		area = 0
		x = a 
		width = (b-a)/n

		for i in range(n):
			area += width * ((f(x) + f(x + width))/2)
			x += width
		print("Area: ", area)

def integration2():
	choice = int(input("1) Rectangle \n2) Trapezoid\n"))

	if(choice == 1):
		n = int(input("How many rectangles: "))
		a = int(input("Enter a: "))
		b = int(input("Enter b: "))

		area = 0
		x = a 
		width = (b-a)/n

		for i in range(n):
			area += width * f2(x)
			x += width
		print("Area: ", area)
	elif(choice == 2):
		n = int(input("How many rectangles: "))
		a = int(input("Enter a: "))
		b = int(input("Enter b: "))

		area = 0
		x = a 
		width = (b-a)/n

		for i in range(n):
			area += width * ((f2(x) + f2(x + width))/2)
			x += width
		print("Area: ", area)

def integration3():
	choice = int(input("1) Rectangle \n2) Trapezoid\n"))

	if(choice == 1):
		n = int(input("How many rectangles: "))
		a = int(input("Enter a: "))
		b = int(input("Enter b: "))

		area = 0
		x = a 
		width = (b-a)/n

		for i in range(n):
			area += width * f3(x)
			x += width
		print("Area: ", area)
	elif(choice == 2):
		n = int(input("How many rectangles: "))
		a = int(input("Enter a: "))
		b = int(input("Enter b: "))

		area = 0
		x = a 
		width = (b-a)/n

		for i in range(n):
			area += width * ((f3(x) + f3(x + width))/2)
			x += width
		print("Area: ", area)

main()