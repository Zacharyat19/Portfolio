#include <iostream>

int **makeBoard(int length) {
    int **board = new int *[length];
    for(int i = 0; i < length; i++) {
        board[i] = new int[3];
        for(int j = 0; j < 3; j++) {
            board[i][j] = 0;
        }
        
    }
    for(int i = 0; i < length; i++) {
        board[i][0] = i + 1;
    }
    return board;
}

void deleteBoard(int **b, int length) {
    for(int i = 0; i < length; i++) {
        delete []b[i];
    }
    delete []b;
}

//Unknown bug
void moveDisk(int fromCol, int toCol, int length, int **b) {
    int x = 0;
    for(int i = 0; i < length; i++) {
        if(b[i][fromCol] != 0) {
            x = b[i][fromCol];
            b[i][fromCol] = 0;
            break;
        }
    }
    for(int i = length - 1; i >= 0; i--) {
        if (b[i][toCol] == 0) {
            b[i][toCol] = x;
            break;
        }
    }
}

void towers(int numberOfdisks, int **b, int fromCol, int toCol, int spare, int length) {
    if(numberOfdisks >= 1) {
        towers(numberOfdisks - 1, b, fromCol, spare, toCol, length);
        //move disk
        moveDisk(fromCol, toCol, length, b);
        //print board
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < 3; j++) {
                std::cout << b[i][j] << " "; 
            }
            std::cout << std::endl;
        }
        std::cout << "-----" << std::endl;
        towers(numberOfdisks - 1, b, spare, toCol, fromCol, length);
    }
}

int main() {
    int length = 0;
    std::cout << "How many rings do you want: " << std::endl;
    std::cin >> length;
    std::cin.ignore();
    std::cin.clear();

    int **board = makeBoard(length);
    towers(length, board,1,2,3,length);
    deleteBoard(board, length);
}