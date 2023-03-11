#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

void playerVsAi(char **b, int rows, int col, int choice);
char **makeBoard(int rows, int col);
void deleteBoard(char **b, int rows);
void twoPlayer(char **b, int rows, int col);
void playerOneMove(char **b, int rows, int col);
void playerTwoMove(char **b, int rows, int col);
void compMove(char **b, int rows, int col);
bool isWinPlayer(char **b, int rows, int col);
bool isWinComp(char **b, int rows, int col);
bool isWinTwo(char **b, int rows, int col);
bool isTie(char **b, int rows, int col);
void printBoard(char **b, int rows, int col);
void clearBoard(char **b, int rows, int col);


/******************************************************
** Function: main
** Description: gets command line arguments
** Parameters: int argc, char *argv[]
** Pre-Conditions: there are spaces inbetween arguments
** Post-Conditions: runs the appropriate play function
*******************************************************/
int main(int argc, char *argv[]) {
    int numPlayers;
    int rows;
    int col;

    if(argc != 4) {
        std::cout << "Entered too many/too few arguments." << std::endl;
        while(numPlayers > 2 || numPlayers < 1) {
            std::cout << "Enter the number of players: " << std::endl;
            while(!(std::cin >> numPlayers)) {
                std::cin.clear();
                std::cin.ignore(123, '\n');
            }
        }
        while(rows > 20 || rows < 4) {
            std::cout << "Enter the number of rows: " << std::endl;
            while(!(std::cin >> rows)) {
                std::cin.clear();
                std::cin.ignore(123, '\n');
            }
        }
        while(col > 20 || col < 4) {
            std::cout << "Enter the number of colomns: " << std::endl;
            while(!(std::cin >> col)) {
                std::cin.clear();
                std::cin.ignore(123, '\n');
            }
        }
    } else if(argc == 4){
        numPlayers = atoi(argv[1]);
        rows = atoi(argv[2]);
        col = atoi(argv[3]);
    }
    

    char **board = makeBoard(rows, col);

    if(numPlayers == 1) {
        std::cout << "Do you want to go first(1. yes, 0. no)" << std::endl;
        int choice;
        std::cin >> choice;
        playerVsAi(board, rows, col, choice);
    } else if(numPlayers == 2) {
        twoPlayer(board, rows, col);
    }
    return 0;
}


/***********************************************************
** Function: makeBoard
** Description: creates a dynamic 2D array game board
** Parameters: int rows, int col
** Pre-Conditions: rows and col have been type casted to int
** Post-Conditions: returns a 2D array
************************************************************/
char **makeBoard(int rows, int col) {
    char **board = new char*[rows];
    for(int i = 0; i < col; i++) {
        board[i] = new char[col];
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++) {
            board[i][j] = ' ';
        }
    }
    return board;
}


/***********************************************************
** Function: clearBoard
** Description: clears the board
** Parameters: char **b, int rows, int col
** Pre-Conditions: rows and col have been type casted to int
** Post-Conditions: returns a 2D array
************************************************************/
void clearBoard(char **b, int rows, int col) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++) {
            b[i][j] = ' ';
        }
    }
}


/**************************************************************
** Function: deleteBoard
** Description: deletes the board and frees up heap memory
** Parameters: char **b, int rows, int col
** Pre-Conditions: b is a 2D array, rows are type casted to int
** Post-Conditions: b is deleted off the heap
***************************************************************/
void deleteBoard(char **b, int rows) {
    for(int i = 0; i < rows; i++) {
        delete [] b[i];
    }
    delete []b;
}


/**************************************************************
** Function: printBoard
** Description: prints the board
** Parameters: char **b, int rows, int col
** Pre-Conditions: b is a 2D array, rows are type casted to int
** Post-Conditions: b is printed
***************************************************************/
void printBoard(char **b, int rows, int col) {
    for (int i = 0; i < col; ++i)
                std::cout << "  "<< i+1 << " ";
        
            std::cout << std::endl;

            for (int i = 0; i < rows; i++){
                for (int j = 0; j < col; j++){
                    if (i % 2 == 0 && j % 2 == 0)
                        std::cout << "|\033[30;47m " << b[i][j] << " "; 
                    else if (i % 2 == 1 && j % 2 == 1)
                        std::cout << "|\033[30;47m " << b[i][j] << " ";
                    else
                        std::cout << "|\033[0m " << b[i][j] << " ";
                    std::cout << "\033[0m";
                }
                std::cout << std::endl;
            }
}


/********************************************************************************
** Function: playerVsAi
** Description: plays a game of Connect Four with an AI
** Parameters: char **b, int rows, int col
** Pre-Conditions: b is a 2D array, rows and col are type casted to int
** Post-Conditions: prints out the board and asks if the player wants to go again
*********************************************************************************/
void playerVsAi(char **b, int rows, int col, int choice) {
    if(choice == 1) {
        bool cont = true;

        std::cout << "Select a colomn, you are X." << std::endl;
        printBoard(b, rows, col);

        while(cont) {
            int move;
            while(!(std::cin >> move)) {
                std::cin.clear();
                std::cin.ignore(123, '\n');
            }

            //player move
            for(int i = 0; i < rows; i++) {
                if(b[rows - 1 - i][move - 1] != 'O' && b[rows - 1 - i][move - 1] != 'X') {
                    b[rows - 1 - i][move - 1] = 'X';
                    break;
                } else if(b[0][move - 1] != ' ') {
                    std::cout << "Invalid move, try again" << std::endl;
                    playerVsAi(b, rows, col, choice);
                }
            }

            //print board and check winner
            std::cout << "\n" << std::endl;
            std::cout << "Your move" << std::endl;
            printBoard(b, rows, col);
            if(isWinPlayer(b, rows, col)) {
                std::cout << "Player wins." << std::endl;
                break;
            }

            //computer move and win check
            std::cout << "\n" << std::endl;
            std::cout << "Computer move" << std::endl;
            compMove(b, rows, col);
            printBoard(b, rows, col);
            if(isWinComp(b, rows, col)) {
                std::cout << "Computer wins" << std::endl;
                break;
            }

            //tie check
            if(isTie(b, rows, col)) {
                std::cout << "Tie" << std::endl;
                break;
            }
        }

        //clear board and ask if the user wants to play again
        clearBoard(b, rows, col);
        bool playAgain = true;
        while(playAgain) {
            std::cout << "Do you want to play again(1. yes, 0. no)" << std::endl;
            int x;
            std::cin >> x;
            if(x == 1) {
                playerVsAi(b, rows, col, choice);
            } else if(x == 0) {
                deleteBoard(b, rows);
                break;
            } else if(x != 1 || x != 0) {
                std::cout << "Invalid input" << std::endl;
            }
        }
    } else if(choice == 0) {
        bool cont = true;
        printBoard(b, rows, col);

        while(cont) {
            //computer move
            std::cout << "\n" << std::endl;
            std::cout << "Computer move" << std::endl;
            compMove(b, rows, col);
            printBoard(b, rows, col);
            if(isWinComp(b, rows, col)) {
                std::cout << "Computer wins" << std::endl;
                break;
            }

            int move;
            while(!(std::cin >> move)) {
                std::cin.clear();
                std::cin.ignore(123, '\n');
            }

            //player move
            for(int i = 0; i < rows; i++) {
                if(b[rows - 1 - i][move - 1] != 'O' && b[rows - 1 - i][move - 1] != 'X') {
                    b[rows - 1 - i][move - 1] = 'X';
                    break;
                } else if(b[0][move - 1] != ' ') {
                    std::cout << "Invalid move" << std::endl;
                    playerVsAi(b, rows, col, choice);

                }
            }

            //print board and check winner
            std::cout << "\n" << std::endl;
            std::cout << "Your move" << std::endl;
            printBoard(b, rows, col);
            if(isWinPlayer(b, rows, col)) {
                std::cout << "Player wins." << std::endl;
                break;
            }

            //tie check
            if(isTie(b, rows, col)) {
                std::cout << "Tie" << std::endl;
                break;
            }
        }

        //clear board and ask if the user wants to play again
        clearBoard(b, rows, col);
        bool playAgain = true;
        while(playAgain) {
            std::cout << "Do you want to play again(1. yes, 0. no)" << std::endl;
            int x;
            std::cin >> x;
            if(x == 1) {
                playerVsAi(b, rows, col, choice);
            } else if(x == 0) {
                deleteBoard(b, rows);
                break;
            } else if(x != 1 || x != 0) {
                std::cout << "Invalid input" << std::endl;
            }
        }
    }
}


/*********************************************************************************
** Function: twoPlayer
** Description: plays a game of Connect Four with two players
** Parameters: char **b, int rows, int col
** Pre-Conditions: b is a 2D array, rows and col are type casted to int
** Post-Conditions: prints out the board and asks if the players wants to go again
**********************************************************************************/
void twoPlayer(char **b, int rows, int col) {
    bool cont = true;

    std::cout << "Select a colomn player one, you are X." << std::endl;
    printBoard(b, rows, col);

    while(cont) {
        //player one move
        playerOneMove(b, rows, col);
        
        //print board and check winner
        std::cout << "\n" << std::endl;
        std::cout << "Player one's move" << std::endl;
        printBoard(b, rows, col);
        if(isWinPlayer(b, rows, col)) {
            std::cout << "Player one wins." << std::endl;
            break;
        }

        //tie check
        if(isTie(b, rows, col)) {
            std::cout << "Tie" << std::endl;
            break;
        }

        //player two move
        playerTwoMove(b, rows, col);

        //print board and check winner
        std::cout << "\n" << std::endl;
        std::cout << "Player two's move" << std::endl;
        printBoard(b, rows, col);
        if(isWinTwo(b, rows, col)) {
            std::cout << "Player two wins" << std::endl;
            break;
        }

        //tie check
        if(isTie(b, rows, col)) {
            std::cout << "Tie" << std::endl;
            break;
        }
    }

    //clear board and ask if the user wants to play again
    clearBoard(b, rows, col);
    bool playAgain = false;
    while(playAgain) {
        std::cout << "Do you want to play again(1. yes, 2. no)" << std::endl;
        int x;
        std::cin >> x;
        if(x == 1) {
            twoPlayer(b, rows, col);
        } else if(x == 0) {
            deleteBoard(b, rows);
            break;
        } else if(x != 1 || x != 0) {
            std::cout << "Invalid input" << std::endl;
        }
    }
}


/**********************************************************************
** Function: playerOneMove
** Description: places a piece for player one
** Parameters: char **b, int rows, int col
** Pre-Conditions: b is a 2D array, rows and col are type casted to int
** Post-Conditions: X is placed correctly on the board
***********************************************************************/
void playerOneMove(char **b, int rows, int col) {
    int move;
    while(!(std::cin >> move)) {
        std::cin.clear();
        std::cin.ignore(123, '\n');
    }

    for(int i = 0; i < rows; i++) {
        if(b[rows - 1 - i][move - 1] == ' ') {
            b[rows - 1 - i][move - 1] = 'X';
            break;
        } else if(b[0][move - 1] != ' ') {
            std::cout << "Invalid move, try again" << std::endl;
            playerOneMove(b, rows, col);
        }
    }
}


/**********************************************************************
** Function: playerTwoMove
** Description: places a piece for player two
** Parameters: char **b, int rows, int col
** Pre-Conditions: b is a 2D array, rows and col are type casted to int
** Post-Conditions: O is placed correctly on the board
***********************************************************************/
void playerTwoMove(char **b, int rows, int col) {
    int move;
    while(!(std::cin >> move)) {
        std::cin.clear();
        std::cin.ignore(123, '\n');
    }

    for(int i = 0; i < rows; i++) {
        if(b[rows - 1 - i][move - 1] == ' ') {
            b[rows - 1 - i][move - 1] = 'O';
            break;
        } else if(b[0][move - 1] != ' ') {
            std::cout << "Invalid move, try again" << std::endl;
            playerTwoMove(b, rows, col);

        }
    }
}


/**************************************************************
** Function: compMove
** Description: places a piece on the board for the computer
** Parameters: char **b, int rows, int col, int *p
** Pre-Conditions: b is a 2D array, ints are type casted to int
** Post-Conditions: 'O' is placed in a valid spot
***************************************************************/
void compMove(char **b, int rows, int col) {
    srand(time(NULL));
    int move = (rand() % (col - 1));

    for(int i = 0; i < rows; i++) {
        if(b[rows - 1 - i][move - 1] != 'O' && b[rows - 1 - i][move - 1] != 'X') {
            b[rows - 1 - i][move - 1] = 'O';
            break;
                        
        }
    }
}



/**************************************************************
** Function: isWinPlayer
** Description: checks for four X's in a row
** Parameters: char **b, int rows, int col
** Pre-Conditions: b is a 2D array, ints are type casted to int
** Post-Conditions: return true if a win is found
***************************************************************/
bool isWinPlayer(char **b, int rows, int col) {
    //horizontal
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col - 3; j++) {
            if(b[i][j] == 'X' && b[i][j + 1] == 'X' && b[i][j + 2] == 'X' && b[i][j + 3] == 'X') {
                return true;
            }
        }
    }

    //verticle
    for(int i = 0; i < rows - 3; i++) {
        for(int j = 0; j < col; j++) {
            if(b[i][j] == 'X' && b[i + 1][j] == 'X' && b[i + 2][j] == 'X' && b[i + 3][j] == 'X') {
                return true;
            }
        }
    }

    // ascendingDiagonalCheck 
    for (int i = 3; i < col; i++){
        for (int j = 0; j < rows - 3; j++){
            if (b[i][j] == 'X' && b[i - 1][j + 1] == 'X' && b[i - 2][j + 2] == 'X' && b[i - 3][j + 3] == 'X') {
                return true;
            }
        }
    }

    // descendingDiagonalCheck
    for (int i = 3; i < col; i++){
        for (int j = 3; j < rows; j++){
            if (b[i][j] == 'X' && b[i - 1][j - 1] == 'X' && b[i - 2][j - 2] == 'X' && b[i - 3][j - 3] == 'X') {
                return true;
            }
        }
    }
    return false;
}


/**************************************************************
** Function: isWinTwo
** Description: checks for four O's in a row
** Parameters: char **b, int rows, int col
** Pre-Conditions: b is a 2D array, ints are type casted to int
** Post-Conditions: return true if a win is found
***************************************************************/
bool isWinTwo(char **b, int rows, int col) {
    //horizontal
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col - 3; j++) {
            if(b[i][j] == 'O' && b[i][j + 1] == 'O' && b[i][j + 2] == 'O' && b[i][j + 3] == 'O') {
                return true;
            }
        }
    }

    //verticle
    for(int i = 0; i < rows - 3; i++) {
        for(int j = 0; j < col; j++) {
            if(b[i][j] == 'O' && b[i + 1][j] == 'O' && b[i + 2][j] == 'O' && b[i + 3][j] == 'O') {
                return true;
            }
        }
    }

    // ascendingDiagonalCheck 
    for (int i = 3; i < col; i++){
        for (int j = 0; j < rows - 3; j++){
            if (b[i][j] == 'O' && b[i - 1][j + 1] == 'O' && b[i - 2][j + 2] == 'O' && b[i - 3][j + 3] == 'O') {
                return true;
            }
        }
    }

    // descendingDiagonalCheck
    for (int i = 3; i < col; i++){
        for (int j = 3; j < rows; j++){
            if (b[i][j] == 'O' && b[i - 1][j - 1] == 'O' && b[i - 2][j - 2] == 'O' && b[i - 3][j - 3] == 'O') {
                return true;
            }
        }
    }
    return false;
}


/**************************************************************
** Function: isWinComp
** Description: checks for four O's in a row 
** Parameters: char **b, int rows, int col
** Pre-Conditions: b is a 2D array, ints are type casted to int
** Post-Conditions: return true if a win is found
***************************************************************/
bool isWinComp(char **b, int rows, int col) {
    //horizontal
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col - 3; j++) {
            if(b[i][j] == 'O' && b[i][j + 1] == 'O' && b[i][j + 2] == 'O' && b[i][j + 3] == 'O') {
                return true;
            }
        }
    }

    //verticle
    for(int i = 0; i < rows - 3; i++) {
        for(int j = 0; j < col; j++) {
            if(b[i][j] == 'O' && b[i + 1][j] == 'O' && b[i + 2][j] == 'O' && b[i + 3][j] == 'O') {
                return true;
            }
        }
    }

    // ascendingDiagonalCheck 
    for (int i = 3; i < col; i++){
        for (int j = 0; j < rows - 3; j++){
            if (b[i][j] == 'O' && b[i - 1][j + 1] == 'O' && b[i - 2][j + 2] == 'O' && b[i - 3][j + 3] == 'O') {
                return true;
            }
        }
    }

    // descendingDiagonalCheck
    for (int i = 3; i < col; i++){
        for (int j = 3; j < rows; j++){
            if (b[i][j] == 'O' && b[i - 1][j - 1] == 'O' && b[i - 2][j - 2] == 'O' && b[i - 3][j - 3] == 'O') {
                return true;
            }
        }
    }
    return false;
}


/**************************************************************
** Function: isTie
** Description: checks if the game is a tie
** Parameters: char **b, int rows, int col
** Pre-Conditions: b is a 2D array, ints are type casted to int
** Post-Conditions: return true if a tie is found
***************************************************************/
bool isTie(char **b, int rows, int col) {
    int counter = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++) {
            if(b[i][j] != ' ') {
                counter ++;
            }
        }
    }
    if(counter == 0) {
        return true;
    }
    return false;
}