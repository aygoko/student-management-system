#ifndef GRADE_H
#define GRADE_H


class Grade {
private:
    int gradeID;
    int studentID;
    int lessonID;
    int grade;

public:

    Grade();

    Grade(int gradeID, int studentID, int lessonID, int grade);


    void setGradeID(int id);

    int getGradeID() const;

    void setStudentID(int studentID);

    int getStudentID() const;

    void setLessonID(int lessonID);

    int getLessonID() const;

    void setGrade(int grade);

    int getGrade() const;
};


#endif // GRADE_H
