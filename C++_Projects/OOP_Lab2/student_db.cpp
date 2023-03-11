#include <fstream>
#include <iostream>

#include "student_db.h"

student *createStudent(int size) {
    student *students = new student[size];
    return students;
}

void popStudent(student *students, int size, std::ifstream &fin) {
    for(int i = 0; i < size; i++) {
        fin >> students[i].ID >> students[i].firstName >> students[i].lastName >> students[i].major;
    }
}

void deleteStudent(student **students, int size) {
	delete [] (*students);
	*students = NULL;
}

void printStudent(student *students, int size) {
   for(int i = 0; i < size; i++) {
       std::cout << students[i].ID << " " << students[i].firstName << " " << students[i].lastName << " " << students[i].major << std::endl;
   }
}

void sortId(student *students, int size) {
    student temp;
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(students[j].ID < students[i].ID) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}