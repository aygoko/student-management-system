#include "Student.h"


Student::Student() : studentID(0), firstName(""), middleName(""), lastName(""), email(""), phoneNumber(""), address(""),
                     groupID(0), facultyID(0), courseNumber(0) {}


Student::Student(int studentID, const std::string &firstName, const std::string &middleName,
                 const std::string &lastName, const std::string &email, const std::string &phoneNumber,
                 const std::string &address, int groupID, int facultyID, int courseNumber) :
        studentID(studentID), firstName(firstName), middleName(middleName),
        lastName(lastName), email(email), phoneNumber(phoneNumber),
        address(address), groupID(groupID), facultyID(facultyID), courseNumber(courseNumber) {}


void Student::setStudentID(int id) {
    studentID = id;
}

int Student::getStudentID() const {
    return studentID;
}

void Student::setFirstName(const std::string &fName) {
    firstName = fName;
}

const std::string &Student::getFirstName() const {
    return firstName;
}

void Student::setMiddleName(const std::string &mName) {
    middleName = mName;
}

const std::string &Student::getMiddleName() const {
    return middleName;
}

void Student::setLastName(const std::string &lName) {
    lastName = lName;
}

const std::string &Student::getLastName() const {
    return lastName;
}

void Student::setEmail(const std::string &email) {
    this->email = email;
}

const std::string &Student::getEmail() const {
    return email;
}

void Student::setPhoneNumber(const std::string &phone) {
    phoneNumber = phone;
}

const std::string &Student::getPhoneNumber() const {
    return phoneNumber;
}

void Student::setAddress(const std::string &address) {
    this->address = address;
}

const std::string &Student::getAddress() const {
    return address;
}

void Student::setGroupID(int groupID) {
    this->groupID = groupID;
}

int Student::getGroupID() const {
    return groupID;
}

void Student::setFacultyID(int facultyID) {
    this->facultyID = facultyID;
}

int Student::getFacultyID() const {
    return facultyID;
}

void Student::setCourseNumber(int courseNumber) {
    this->courseNumber = courseNumber;
}

int Student::getCourseNumber() const {
    return courseNumber;
}
