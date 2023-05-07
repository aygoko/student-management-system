#include "Lesson.h"


Lesson::Lesson() : lessonID(0) {}

Lesson::Lesson(int lessonID, const std::string &lessonName) : lessonID(lessonID), lessonName(lessonName) {}


void Lesson::setLessonID(int id) {
    lessonID = id;
}

int Lesson::getLessonID() const {
    return lessonID;
}

void Lesson::setLessonName(const std::string &name) {
    lessonName = name;
}

const std::string &Lesson::getLessonName() const {
    return lessonName;
}
