#include "Course.h"

using namespace std;

Course::Course(string name, vector<Group*> groups) : mName(name), mGroups(groups) {}

Course::~Course() {
    for (Group* group : mGroups) {
        delete group;
    }
}

string Course::getName() const {
    return mName;
}

vector<Group*> Course::getGroups() const {
    return mGroups;
}

void Course::addGroup(Group* group) {
    mGroups.push_back(group);
}

void Course::removeGroup(Group* group) {
    for (auto it = mGroups.begin(); it != mGroups.end(); ++it) {
        if (*it == group) {
            mGroups.erase(it);
            delete group;
            break;
        }
    }
}

Group::Group(string name) : mName(name) {}

Group::~Group() {
    for (Student* student : mStudents) {
        delete student;
    }
}

string Group::getName() const {
    return mName;
}

vector<Student*> Group::getStudents() const {
    return mStudents;
}

void Group::addStudent(Student* student) {
    mStudents.push_back(student);
}

void Group::removeStudent(Student* student) {
    for (auto it = mStudents.begin(); it != mStudents.end(); ++it) {
        if (*it == student) {
            mStudents.erase(it);
            delete student;
            break;
        }
    }
}

Student::Student(string name, string group) : mName(name), mGroupName(group) {}

Student::~Student() {}

string Student::getName() const {
    return mName;
}

string Student::getGroupName() const {
    return mGroupName;
}

void Student::setGroupName(string group) {
    mGroupName = group;
}