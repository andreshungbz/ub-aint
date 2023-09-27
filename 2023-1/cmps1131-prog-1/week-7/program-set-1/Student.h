// Student Class Definition

#ifndef PROBLEM_SET_1_STUDENT_H
#define PROBLEM_SET_1_STUDENT_H

#include <string>

class Student {
public:
    // constructor
    Student(const std::string& fn, const std::string& ln);

    // function members
    // firstName setter and getter
    void setFirstName(const std::string& fn);
    [[nodiscard]] const std::string& getFirstName() const;

    // lastName setter and getter
    void setLastName(const std::string& ln);
    [[nodiscard]] const std::string& getLastName() const;

    // dob setter and getter
    void setDob(const std::string& newDob);
    [[nodiscard]] const std::string& getDob() const;

    // gpa setter and getter
    void setGPA(float newGPA);
    [[nodiscard]] float getGPA() const;

    // gender setter and getter
    void setGender(char newGender);
    [[nodiscard]] char getGender() const;

    // status setter and getter
    void setStatus(char newStatus);
    [[nodiscard]] char getStatus() const;

    // id setter and getter
    void setID(const std::string& newID);
    [[nodiscard]] const std::string& getID() const;
private:
    // data members
    std::string firstName;
    std::string lastName;
    std::string dob;
    float gpa;
    char gender;
    char status;
    std::string id;
};

#endif // PROBLEM_SET_1_STUDENT_H
