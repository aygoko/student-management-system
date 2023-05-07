#include "Headers/include/Grade.h"


Grade::Grade() : gradeID(0), studentID(0), lessonID(0), grade(0) {}

Grade::Grade(int gradeID, int studentID, int lessonID, int grade) : gradeID(gradeID), studentID(studentID),
                                                                    lessonID(lessonID), grade(grade) {}


void Grade::setGradeID(int id) {
    gradeID = id;
}

int Grade::getGradeID() const {
    return gradeID;
}

void Grade::setStudentID(int studentID) {
    this->studentID = studentID;
}

int Grade::getStudentID() const {
    return studentID;
}

void Grade::setLessonID(int lessonID) {
    this->lessonID = lessonID;
}

int Grade::getLessonID() const {
    return lessonID;
}

void Grade::setGrade(int grade) {
    this->grade = grade;
}

int Grade::getGrade() const {
    return grade;
}
