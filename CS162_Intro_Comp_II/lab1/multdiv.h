struct multdivEntry {
    int mult;
    float div;
};

bool isValidDimensions(char *m, char *n);
multdivEntry **createTable(int row, int col);
void printTable(multdivEntry **table, int row, int col);
void deleteTable(multdivEntry **table, int row);