#include <fstream>
#include <iostream>
#include <cstdlib>

#include "student_db.h"

int main() {
    std::ifstream fin;

    fin.open("input.txt");
    if(!fin.is_open()) {
        std::cout << "Error opening file to read." << std::endl;
        return 1;
    }


    std::string temp;
    int num;
    std::getline(fin, temp);
    num = atoi(temp.c_str());

    student *students = createStudent(num);
    popStudent(students, num, fin);

    std::ofstream fout;
    fout.open("output.txt");
    if(!fin.is_open()) {
        std::cout << "Error opening file to read." << std::endl;
        return 1;
    }
    
    std::cout << "Unsorted" << std::endl;
    printStudent(students, num);
    sortId(students, num);
    std::cout << "Sorted" << std::endl;
    printStudent(students, num);
    deleteStudent(&students, num);
}