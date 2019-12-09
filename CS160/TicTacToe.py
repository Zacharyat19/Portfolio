import random

def draw_board(board):
    print(' ' + board[1] + ' | ' + board[2] + ' | ' + board[3])
    print('-----------')
    print(' ' + board[4] + ' | ' + board[5] + ' | ' + board[6])
    print('-----------')
    print(' ' + board[7] + ' | ' + board[8] + ' | ' + board[9])

def main():
    user_input = int(input("1) One player\n2) Two players\n"))
    if(user_input <= 0 or user_input > 2):
        print("Invalid input.")
        main()
    elif(user_input == 1):
        one_player()
    elif(user_input == 2):
        two_player()

def one_player():
    win = False
    board = [" "] * 10

    pl1 = ""
    ai = ""
    choice = input("Do you want to use X or O: ")
    if(choice == "X" or choice == "x"):
        pl1 = "X"
        ai = "O"
        while(not win):
            draw_board(board)
            pick = int(input("Pick a spot (1-9), start at the top left and move across: "))

            board[pick] = pl1
            if(is_winX(board)):
                print("Player 1 wins.")
                win = True
            elif(is_winO(board)):
                print("AI wins.")
                win = True

            comp_picO(board)
            if(is_winX(board)):
                print("Player 1 wins.")
                win = True
            elif(is_winO(board)):
                print("AI wins.")
                win = True

    elif(choice == "O" or choice == "o"):
        pl1 = "O"
        ai = "X"
        while(not win):
            draw_board(board)
            pick = int(input("Pick a spot (1-9), start at the top left and move across: "))

            board[pick] = pl1
            if(is_winO(board)):
                print("Player 1 wins.")
                win = True
            elif(is_winX(board)):
                print("AI wins.")
                win = True

            comp_picX(board)
            if(is_winO(board)):
                print("Player 1 wins.")
                win = True
            elif(is_winX(board)):
                print("AI wins.")
                win = True

def two_player():
    win = False
    board = [" "] * 10

    pl1 = ""
    pl2 = ""
    choice = input("Does player 1 want to use X or O: ")
    if(choice == "X" or choice == "x"):
        pl1 = "X"
        pl2 = "O"
        while(not win):
            draw_board(board)
            pick = int(input("Pick a spot (1-9), start at the top left and move across: "))

            board[pick] = pl1
            if(is_winX(board)):
                print("Player 1 wins.")
                win = True
            elif(is_winO(board)):
                print("PLayer 2 wins.")
                win = True
            
            draw_board(board)
            pick2 = int(input("Pick a spot (1-9), start at the top left and move across: "))
            board[pick2] = pl2

            if(is_winX(board)):
                print("Player 1 wins.")
                win = True
            elif(is_winO(board)):
                print("PLayer 2 wins.")
                win = True

    elif(choice == "O" or choice == "o"):
        pl1 = "O"
        pl2 = "X"

        while(not win):
            draw_board(board)
            pick = int(input("Pick a spot (1-9), start at the top left and move across: "))

            board[pick] = pl1
            
            if(is_winO(board)):
                print("Player 1 wins.")
                win = True
            elif(is_winX(board)):
                print("PLayer 2 wins.")
                win = True

            draw_board(board)
            pick2 = int(input("Pick a spot (1-9), start at the top left and move across: "))
            board[pick2] = pl2

            if(is_winO(board)):
                print("Player 1 wins.")
                win = True
            elif(is_winX(board)):
                print("PLayer 2 wins.")
                win = True

def comp_picO(board):
    pick = random.randint(1,9)
    board.pop(pick)
    board.insert(pick,"O")
    if(board[pick] == "X"):
        comp_picO(board)
    else:
        return board

def comp_picX(board):
    pick = random.randint(1,9)
    board.pop(pick)
    board.insert(pick,"X")
    if(board[pick] == "O"):
        comp_picX(board)
    else:
        return board

def is_winX(board):
    if(board[1] == "X" and board[2] == "X" and board[3] == "X"):
        return True
    elif(board[4] == "X" and board[5] == "X" and board[6] == "X"):
        return True
    elif(board[7] == "X" and board[8] == "X" and board[9] == "X"):
        return True
    elif(board[1] == "X" and board[4] == "X" and board[7] == "X"):
        return True
    elif(board[2] == "X" and board[5] == "X" and board[8] == "X"):
        return True
    elif(board[3] == "X" and board[6] == "X" and board[9] == "X"):
        return True
    elif(board[1] == "X" and board[5] == "X" and board[9] == "X"):
        return True
    elif(board[7] == "X" and board[5] == "X" and board[3] == "X"):
        return True
    else:
        return False

def is_winO(board):
    if(board[1] == "O" and board[2] == "O" and board[3] == "O"):
        return True
    elif(board[4] == "O" and board[5] == "O" and board[6] == "O"):
        return True
    elif(board[7] == "O" and board[8] == "O" and board[9] == "O"):
        return True
    elif(board[1] == "O" and board[4] == "O" and board[7] == "O"):
        return True
    elif(board[2] == "O" and board[5] == "O" and board[8] == "O"):
        return True
    elif(board[3] == "O" and board[6] == "O" and board[9] == "O"):
        return True
    elif(board[1] == "O" and board[5] == "O" and board[9] == "O"):
        return True
    elif(board[7] == "O" and board[5] == "O" and board[3] == "O"):
        return True
    else:
        return False

main()