#ifndef TEACHER_H
#define TEACHER_H


#include <string>

class Teacher {
private:
    int teacherID;
    std::string firstName;
    std::string middleName;
    std::string lastName;
    std::string email;
    std::string phoneNumber;
    std::string login;
    std::string password;

public:

    Teacher();

    Teacher(int teacherID, const std::string &firstName, const std::string &middleName, const std::string &lastName,
            const std::string &email, const std::string &phoneNumber, const std::string &login,
            const std::string &password);


    void setTeacherID(int id);

    int getTeacherID() const;

    void setFirstName(const std::string &name);

    const std::string &getFirstName() const;

    void setMiddleName(const std::string &name);

    const std::string &getMiddleName() const;

    void setLastName(const std::string &name);

    const std::string &getLastName() const;

    void setEmail(const std::string &email);

    const std::string &getEmail() const;

    void setPhoneNumber(const std::string &phoneNumber);

    const std::string &getPhoneNumber() const;

    bool authenticate(const std::string &login, const std::string &password) const;
};


#endif // TEACHER_H
