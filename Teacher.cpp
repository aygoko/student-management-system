#include "Teacher.h"


Teacher::Teacher() : teacherID(0) {}

Teacher::Teacher(int teacherID, const std::string &firstName, const std::string &middleName,
                 const std::string &lastName, const std::string &email, const std::string &phoneNumber,
                 const std::string &login, const std::string &password) : teacherID(teacherID), firstName(firstName),
                                                                          middleName(middleName), lastName(lastName),
                                                                          email(email), phoneNumber(phoneNumber),
                                                                          login(login), password(password) {}


void Teacher::setTeacherID(int id) {
    teacherID = id;
}

int Teacher::getTeacherID() const {
    return teacherID;
}

void Teacher::setFirstName(const std::string &name) {
    firstName = name;
}

const std::string &Teacher::getFirstName() const {
    return firstName;
}

void Teacher::setMiddleName(const std::string &name) {
    middleName = name;
}

const std::string &Teacher::getMiddleName() const {
    return middleName;
}

void Teacher::setLastName(const std::string &name) {
    lastName = name;
}

const std::string &Teacher::getLastName() const {
    return lastName;
}

void Teacher::setEmail(const std::string &email) {
    this->email = email;
}

const std::string &Teacher::getEmail() const {
    return email;
}

void Teacher::setPhoneNumber(const std::string &phoneNumber) {
    this->phoneNumber = phoneNumber;
}

const std::string &Teacher::getPhoneNumber() const {
    return phoneNumber;
}

bool Teacher::authenticate(const std::string &login, const std::string &password) const {
    return this->login == login && this->password == password;
}
