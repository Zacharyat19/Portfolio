#include <iostream>

int a_to_i(char character);
void playerVsAi(char **b, int rows, int col);
char **makeBoard(int rows, int col);
void deleteBoard(char **b, int rows);
void twoPlayer(char **b, int rows, int col);

int main(int argc, char *argv[]) {
    int numPlayers = a_to_i(argv[1][0]);
    int rows = a_to_i(argv[2][0]);
    int col = a_to_i(argv[3][0]);

    char **board = makeBoard(rows, col);

    if(numPlayers == 1) {
        playerVsAi(board, rows, col);
    } 
}


/**************************************************************
** Function: a_to_i
** Description: turns a character into a decimal value
** Parameters: char character
** Pre-Conditions: the input is a character
** Post-Conditions: returned the decimal value of the character
***************************************************************/ 
int a_to_i(char character) {
    return (int)character;
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
    return board;
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


/********************************************************************************
** Function: playerVsAi
** Description: plays a game of Connect Four with an AI
** Parameters: char **b, int rows, int col
** Pre-Conditions: b is a 2D array, rows and col are type casted to int
** Post-Conditions: prints out the board and asks if the player wants to go again
*********************************************************************************/
void playerVsAi(char **b, int rows, int col) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < col; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                std::cout << "|\033[30;47m " << b[i][j] << " ";
            } else if (i % 2 == 1 && j % 2 == 1) {
                std::cout << "|\033[30;47m " << b[i][j] << " ";
            } else {
                std::cout << "|\033[0m " << b[i][j] << " ";
                std::cout << "\033[0m";
            }
            std::cout << std::endl;
        }
    }
}