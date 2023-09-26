// Student Class Implementation

#include "Student.h"

// constructor
Student::Student(const std::string& fn, const std::string& ln) {
    setFirstName(fn);
    setLastName(ln);
    setDob("01/01/1900");
    setGPA(0.0);
    setGender('m');
    setStatus('m');
    setID("1000000001");
}

// firstName setter and getter
void Student::setFirstName(const std::string& fn) {
    // https://stackoverflow.com/a/9642381
    firstName = std::any_of(fn.begin(), fn.end(), ::isdigit) ? "" : fn;
}
const std::string& Student::getFirstName() const {
    return firstName;
}

// lastName setter and getter
void Student::setLastName(const std::string& ln) {
    // https://stackoverflow.com/a/9642381
    lastName = std::any_of(ln.begin(), ln.end(), ::isdigit) ? "" : ln;
}
const std::string& Student::getLastName() const {
    return lastName;
}

// dob setter and getter
void Student::setDob(const std::string& newDob) {
    dob = newDob;
}
const std::string& Student::getDob() const {
    return dob;
}

// gpa setter and getter
void Student::setGPA(float newGPA) {
    gpa = (newGPA < 0 || newGPA > 4) ? 0 : newGPA;
}
float Student::getGPA() const {
    return gpa;
}

// gender setter and getter
void Student::setGender(char newGender) {
    gender = (newGender != 'm' && newGender != 'f') ? 'm' : newGender;
}
char Student::getGender() const {
    return gender;
}

// status setter and getter
void Student::setStatus(char newStatus) {
    status = (newStatus != 's' && newStatus != 'm') ? 's' : newStatus;
}
char Student::getStatus() const {
    return status;
}

// id setter and getter
void Student::setID(const std::string& newID) {
    id = newID;
}
const std::string& Student::getID() const {
    return id;
}