#ifndef COURSEWORK_COURSE_H
#define COURSEWORK_COURSE_H


#include <string>
#include <vector>

class Group;

class Student;

class Course {
public:
    Course(std::string name, std::vector<Group *> groups);

    ~Course();

    std::string getName() const;

    std::vector<Group *> getGroups() const;

    void addGroup(Group *group);

    void removeGroup(Group *group);

private:
    std::string mName;
    std::vector<Group *> mGroups;
};

class Group {
public:
    Group(std::string name);

    ~Group();

    std::string getName() const;

    std::vector<Student *> getStudents() const;

    void addStudent(Student *student);

    void removeStudent(Student *student);

private:
    std::string mName;
    std::vector<Student *> mStudents;
};

class Student {
public:
    Student(std::string name, std::string group);

    ~Student();

    std::string getName() const;

    std::string getGroupName() const;

    void setGroupName(std::string group);

private:
    std::string mName;
    std::string mGroupName;
};


#endif
