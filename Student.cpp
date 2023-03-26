#include "Student.h"


Student::Student(int studentId, std::string firstName, std::string lastName, std::string email, std::string phoneNumber,
                 std::string address, Date dateOfBirth, std::string gender)
        : studentId(studentId), firstName(firstName), lastName(lastName), email(email), phoneNumber(phoneNumber),
          address(address), dateOfBirth(dateOfBirth), gender(gender) {}

void Student::addEnrolledCourse(const Course &course) {
    enrolledCourses.push_back(course);
}

void Student::dropEnrolledCourse(const Course &course) {
    for (auto it = enrolledCourses.begin(); it != enrolledCourses.end(); ++it) {
        if (*it == course) {
            enrolledCourses.erase(it);
            break;
        }
    }
}

void Student::addGrade(const Course &course, Grade grade) {
    grades[course] = grade;
}

void Student::updateGrade(const Course &course, Grade grade) {
    grades[course] = grade;
}

void Student::removeGrade(const Course &course) {
    grades.erase(course);
}

float Student::calculateGPA() {
    float totalCredits = 0.0;
    float totalPoints = 0.0;

    for (auto it = grades.begin(); it != grades.end(); ++it) {
        float gradePoints = it->second.getGradePoints();
        int credits = it->first.getCredits();
        totalPoints += gradePoints * credits;
        totalCredits += credits;
    }

    return totalPoints / totalCredits;
}


std::string Student::getFullName() {
    return firstName + " " + lastName;
}

std::string Student::getEmail() {
    return email;
}

std::string Student::getPhoneNumber() {
    return phoneNumber;
}

std::string Student::getAddress() {
    return address;
}

Date Student::getDateOfBirth() {
    return dateOfBirth;
}

std::string Student::getGender() {
    return gender;
}

std::vector <Course> Student::getEnrolledCourses() {
    return enrolledCourses;
}

std::map <Course, Grade> Student::getGrades() {
    return grades;
}

int Student::getStudentId() {
    return studentId;
}


