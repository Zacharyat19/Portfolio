#include <fstream>

#ifndef STUDENT_DB_H
#define STUDENT_DB_H
struct student {
    int ID;
    std::string firstName;
    std::string lastName;
    std::string major;
};

student *createStudent(int);
void popStudent(student *, int, std::ifstream &);
void deleteStudent(student **, int);
void sortId(student *, int);
void printStudent(student *, int);
#endif