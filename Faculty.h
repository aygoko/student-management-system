#ifndef FACULTY_H
#define FACULTY_H

#include <string>
#include <unordered_map>
#include "group.h"

class Faculty {
private:
    int facultyID;
    std::string facultyName;
    std::unordered_map<int, Group> groups;

public:

    Faculty();

    Faculty(int facultyID, const std::string &facultyName);


    void setFacultyID(int id);

    int getFacultyID() const;

    void setFacultyName(const std::string &name);

    const std::string &getFacultyName() const;


    void addGroup(const Group &group);

    void removeGroup(int groupID);

    Group *findGroup(int groupID);

    const std::unordered_map<int, Group> &getGroups() const;
};


#endif // FACULTY_H
