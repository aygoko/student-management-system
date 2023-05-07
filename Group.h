#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <unordered_map>
#include "student.h"

class Group {
private:
    int groupID;
    std::string groupName;
    std::unordered_map<int, Student> students;

public:

    Group();

    Group(int groupID, const std::string &groupName);


    void setGroupID(int id);

    int getGroupID() const;

    void setGroupName(const std::string &name);

    const std::string &getGroupName() const;


    void addStudent(const Student &student);

    void removeStudent(int studentID);

    Student *findStudent(int studentID);

    const std::unordered_map<int, Student> &getStudents() const;
};

#endif // GROUP_H
