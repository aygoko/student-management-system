#include "Faculty.h"


Faculty::Faculty() : facultyID(0) {}

Faculty::Faculty(int facultyID, const std::string &facultyName) : facultyID(facultyID), facultyName(facultyName) {}


void Faculty::setFacultyID(int id) {
    facultyID = id;
}

int Faculty::getFacultyID() const {
    return facultyID;
}

void Faculty::setFacultyName(const std::string &name) {
    facultyName = name;
}

const std::string &Faculty::getFacultyName() const {
    return facultyName;
}

void Faculty::addGroup(const Group &group) {
    groups.emplace(group.getGroupID(), group);
}

void Faculty::removeGroup(int groupID) {
    auto it = groups.find(groupID);
    if (it != groups.end()) {
        groups.erase(it);
    }
}

Group *Faculty::findGroup(int groupID) {
    auto it = groups.find(groupID);
    if (it != groups.end()) {
        return &(it->second);
    }
    return nullptr;
}

const std::unordered_map<int, Group> &Faculty::getGroups() const {
    return groups;
}
