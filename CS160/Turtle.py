import turtle
from random import randint
turtle = turtle.Turtle()

def main():
  try:
    user_input = int(input("How many random words would you like to make: "))
    if(user_input < 1):
      print("Invalid input.")
      main()

    counter = 0

    while(counter <= user_input):
      num = randint(0,4)
      if(num == 1):
        draw_FUN()
      elif(num == 2):
        draw_AIR()
      elif(num == 3):
        draw_ZT()
      elif(num == 4):
        draw_EAT()
        
      counter += 1
  except ValueError:
    print("Invalid input.")
    main()

  

def draw_FUN():
  draw_F()
  draw_U()
  draw_N()
  turtle.clear()

def draw_ZT():
  draw_Z()
  draw_T()
  turtle.clear()

def draw_AIR():
  draw_A()
  draw_I()
  draw_R()
  turtle.clear()

def draw_EAT():
  draw_E()
  draw_A2()
  draw_T2()
  turtle.clear()

def draw_E():
  turtle.goto(0,0)
  turtle.hideturtle()
  turtle.pendown()
  turtle.left(90)
  turtle.forward(40)
  turtle.right(90)
  turtle.forward(30)
  turtle.backward(30)
  turtle.right(90)
  turtle.forward(20)
  turtle.left(90)
  turtle.forward(30)
  turtle.backward(30)
  turtle.right(90)
  turtle.forward(20)
  turtle.left(90)
  turtle.forward(30)
  turtle.penup()

def draw_A2():
  turtle.goto(40,0)
  turtle.pendown()
  turtle.left(60)
  turtle.forward(40)
  turtle.right(115)
  turtle.forward(40)
  turtle.backward(20)
  turtle.left(238)
  turtle.forward(20)
  turtle.right(180)
  turtle.penup()

def draw_T2():
  turtle.goto(110,0)
  turtle.pendown()
  turtle.pendown()
  turtle.left(90)
  turtle.forward(40)
  turtle.right(90)
  turtle.forward(20)
  turtle.left(180)
  turtle.forward(40)
  turtle.right(180)
  turtle.penup()

def draw_A():
  turtle.goto(0,0)
  turtle.hideturtle()
  turtle.pendown()
  turtle.left(60)
  turtle.forward(40)
  turtle.right(115)
  turtle.forward(40)
  turtle.backward(20)
  turtle.left(238)
  turtle.forward(20)
  turtle.right(180)
  turtle.penup()

def draw_I():
  turtle.goto(60,0)
  turtle.pendown()
  turtle.forward(30)
  turtle.backward(15)
  turtle.left(90)
  turtle.forward(40)
  turtle.right(90)
  turtle.forward(15)
  turtle.left(180)
  turtle.forward(30)
  turtle.penup()

def draw_R():
  turtle.goto(110,0)
  turtle.pendown()
  turtle.right(90)
  turtle.forward(43)
  turtle.right(90)
  turtle.circle(-13,180,10)
  turtle.left(130)
  turtle.forward(25)
  turtle.left(47)
  turtle.penup()

def draw_F():
  turtle.goto(0,0)
  turtle.pendown()
  turtle.hideturtle()
  turtle.left(90)
  turtle.forward(40)
  turtle.right(90)
  turtle.forward(20)
  turtle.backward(20)
  turtle.right(90)
  turtle.forward(15)
  turtle.left(90)
  turtle.forward(20)
  turtle.penup()

def draw_U():
  turtle.goto(30,25)
  turtle.pendown()
  turtle.right(90)
  for i in range(5):
        turtle.forward(15)
        turtle.left(45)
  turtle.penup()
 
def draw_N():
  turtle.goto(80,0)
  turtle.pendown()
  turtle.right(45)
  turtle.forward(40)
  turtle.right(140)
  turtle.forward(50)
  turtle.left(140)
  turtle.forward(40)
  turtle.right(90)
  turtle.penup()

def draw_Z():
  turtle.goto(0,0)
  turtle.pendown()
  turtle.hideturtle()
  turtle.forward(40)
  turtle.right(150)
  turtle.forward(44)
  turtle.left(150)
  turtle.forward(40)
  turtle.penup()

def draw_T():
  turtle.goto(70,-23)
  turtle.pendown()
  turtle.left(90)
  turtle.forward(26)
  turtle.right(90)
  turtle.forward(20)
  turtle.left(180)
  turtle.forward(40)
  turtle.right(180)
  turtle.penup()


main()