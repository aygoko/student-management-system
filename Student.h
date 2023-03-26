#ifndef COURSEWORK_STUDENT_H
#define COURSEWORK_STUDENT_H

#include <string>
#include <vector>
#include <map>
#include "Course.h"
#include "Date.h"
#include "Grade.h"

class Student {
private:
    int studentId;
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string phoneNumber;
    std::string address;
    Date dateOfBirth;
    std::string gender;
    std::vector <Course> enrolledCourses;
    std::map <Course, Grade> grades;

public:
    Student(int studentId, std::string firstName, std::string lastName, std::string email, std::string phoneNumber,
            std::string address, Date dateOfBirth, std::string gender);

    void addEnrolledCourse(const Course &course);

    void dropEnrolledCourse(const Course &course);

    void addGrade(const Course &course, Grade grade);

    void updateGrade(const Course &course, Grade grade);

    void removeGrade(const Course &course);

    float calculateGPA();

    std::string getFullName();

    std::string getEmail();

    std::string getPhoneNumber();

    std::string getAddress();

    Date getDateOfBirth();

    std::string getGender();

    std::vector <Course> getEnrolledCourses();

    std::map <Course, Grade> getGrades();

    int getStudentId();
};


#endif