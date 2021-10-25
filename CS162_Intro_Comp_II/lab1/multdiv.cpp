#include <iostream>
#include <stdlib.h>
#include "multdiv.h"

bool isValidDimensions(char *m, char *n) {
    int x = atoi(m);
    int y = atoi(n);

    if(x > 0 && x <= 9) {
        return true;
    } else if(y > 0 && y <= 9) {
        return true;
    }
    return false;
}

multdivEntry **createTable(int row, int col) {
    multdivEntry **table = new multdivEntry*[row];
    for(int i = 0; i < row; i++) {
        table[i] = new multdivEntry[col];
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            table[i][j].mult = (i + 1) * (j + 1);
            if(i == 0 || j == 0) {
                table[i][j].div = 0;
            } else {
                table[i][j].div = float(i) / j;
            }
        }
    }
    return table;
}

void printTable(multdivEntry **table, int row, int col) {
    std::cout << "Multiplication Table:" << std::endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            std::cout << table[i][j].mult << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Division Table:" << std::endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            std::cout << table[i][j].div << " ";
        }
        std::cout << std::endl;
    }
}

void deleteTable(multdivEntry **table, int row) {
    for(int i = 0; i < row; i++) {
        delete table[i];
    }
    delete table;
}