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
    board = [
        [0,0,0,],
        [0,0,0,],
        [0,0,0]]
    for i in range(board - 1):
        for j in i:
            print(board[i][j])
    
one_player()