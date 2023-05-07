#ifndef STUDENT_H
#define STUDENT_H


#include <string>

class Student {
private:
    int studentID;
    std::string firstName;
    std::string middleName;
    std::string lastName;
    std::string email;
    std::string phoneNumber;
    std::string address;
    int groupID;
    int facultyID;
    int courseNumber;

public:
    // Constructors
    Student();

    Student(int studentID, const std::string &firstName, const std::string &middleName,
            const std::string &lastName, const std::string &email, const std::string &phoneNumber,
            const std::string &address, int groupID, int facultyID, int courseNumber);

    // Getters and Setters
    void setStudentID(int id);

    int getStudentID() const;

    void setFirstName(const std::string &fName);

    const std::string &getFirstName() const;

    void setMiddleName(const std::string &mName);

    const std::string &getMiddleName() const;

    void setLastName(const std::string &lName);

    const std::string &getLastName() const;

    void setEmail(const std::string &email);

    const std::string &getEmail() const;

    void setPhoneNumber(const std::string &phone);

    const std::string &getPhoneNumber() const;

    void setAddress(const std::string &address);

    const std::string &getAddress() const;

    void setGroupID(int groupID);

    int getGroupID() const;

    void setFacultyID(int facultyID);

    int getFacultyID() const;

    void setCourseNumber(int courseNumber);

    int getCourseNumber() const;
};


#endif // STUDENT_H
