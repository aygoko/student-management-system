#ifndef LESSON_H
#define LESSON_H

#include <string>

class Lesson {
private:
    int lessonID;
    std::string lessonName;

public:

    Lesson();

    Lesson(int lessonID, const std::string &lessonName);

    void setLessonID(int id);

    int getLessonID() const;

    void setLessonName(const std::string &name);

    const std::string &getLessonName() const;
};

#endif // LESSON_H
