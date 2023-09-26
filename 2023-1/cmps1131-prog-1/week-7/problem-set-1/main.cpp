// [CMPS1131-1] Programming 1
// Problem Set 1
// Andres Hung
// Date Due: October 9, 2023

#include <iostream>
#include "Student.h"

void printStudent(const Student& stu);

int main() {
    Student s1{"John", "Doe"};
    printStudent(s1);

    s1.setFirstName("Jo");
    s1.setID("2020150000");
    s1.setDob("19/11/2019");
    s1.setGPA(4.1);
    s1.setGPA(-0.4);
    s1.setGPA(3.75);
    s1.setGender('j');
    s1.setGender(' ');
    s1.setGender('f');
    s1.setStatus('s');
    s1.setFirstName("j0hn");
    s1.setFirstName("John");
    s1.setLastName("Do3");
    s1.setLastName("Doe");
    printStudent(s1);

    return 0;
}

void printStudent(const Student& stu) {
    std::cout << "*******************************************" << std::endl;
    std::cout << "Student ID: " << stu.getID() << std::endl;
    std::cout << "Student first name: " << stu.getFirstName() << std::endl;
    std::cout << "Student last name: " << stu.getLastName() << std::endl;
    std::cout << "Student DOB: " << stu.getDob() << std::endl;
    std::cout << "Student gender: " << stu.getGender() << std::endl;
    std::cout << "Student status: " << stu.getStatus() << std::endl;
    std::cout << "Student GPA: " << stu.getGPA() << std::endl;
    std::cout << "*******************************************" << std::endl;
}