#include <iostream>
#include "Headers/include/Teacher.h"
#include "Headers/include/Student.h"
#include "Headers/include/Faculty.h"
#include "Headers/include/Group.h"
#include "Headers/include/Grade.h"
#include "Headers/include/Lesson.h"
#include <limits>
#include <unordered_map>
#include <iomanip>


void displayMenu() {
    const int width = 40;

    std::cout << std::string(width, '-') << std::endl;
    std::cout << std::setw((width - 10) / 2) << "" << "MAIN MENU" << std::setw((width - 10) / 2) << "" << std::endl;
    std::cout << std::string(width, '-') << std::endl;

    std::cout << std::endl;
    std::cout << std::left << std::setw(width / 2) << "  1. Search by student" << std::endl;
    std::cout << std::left << std::setw(width / 2) << "  2. Review grades" << std::endl;
    std::cout << std::left << std::setw(width / 2) << "  3. Exit" << std::endl;
    std::cout << std::endl;

    std::cout << std::string(width, '-') << std::endl;
}


void displayStudentInfo(const Student &student) {
    std::cout << "Student information:" << std::endl;
    std::cout << "ID: " << student.getStudentID() << std::endl;
    std::cout << "Name: " << student.getFirstName() << " " << student.getMiddleName() << " " << student.getLastName()
              << std::endl;
    std::cout << "Email: " << student.getEmail() << std::endl;
    std::cout << "Phone Number: " << student.getPhoneNumber() << std::endl;
    std::cout << "Address: " << student.getAddress() << std::endl;
    std::cout << "Group ID: " << student.getGroupID() << std::endl;
    std::cout << "Faculty ID: " << student.getFacultyID() << std::endl;
    std::cout << "Course Number: " << student.getCourseNumber() << std::endl;
}

bool teacherLogin(Teacher &teacher) {
    std::string login, password;
    std::cout << "Enter your login: ";
    std::cin >> login;
    std::cout << "Enter your password: ";
    std::cin >> password;

    return teacher.authenticate(login, password);
}


int
searchStudent(std::unordered_map<int, Student> &students, const std::string &firstName, const std::string &middleName,
              const std::string &lastName) {
    for (auto &[id, student]: students) {
        if (student.getFirstName() == firstName && student.getMiddleName() == middleName &&
            student.getLastName() == lastName) {
            return id;
        }
    }
    return -1;
}

int findGroupID(const std::unordered_map<int, Group> &groups, const std::string &groupName) {
    for (const auto &[id, group]: groups) {
        if (group.getGroupName() == groupName) {
            return id;
        }
    }
    return -1;
}

void displayGroupStudentsAndGrades(const std::unordered_map<int, Student> &students,
                                   const std::unordered_map<int, Grade> &grades,
                                   const std::unordered_map<int, Lesson> &lessons, int groupID) {
    std::cout << "Students in group " << groupID << " and their grades:" << std::endl;
    for (const auto &[id, student]: students) {
        if (student.getGroupID() == groupID) {
            std::cout << "Student ID: " << student.getStudentID() << std::endl;
            std::cout << "Name: " << student.getFirstName() << " " << student.getMiddleName() << " "
                      << student.getLastName()
                      << std::endl;

            for (const auto &[id, grade]: grades) {
                if (grade.getStudentID() == student.getStudentID()) {
                    int lessonID = grade.getLessonID();
                    std::string lessonName;
                    for (const auto &[id, lesson]: lessons) {
                        if (lesson.getLessonID() == lessonID) {
                            lessonName = lesson.getLessonName();
                            break;
                        }
                    }

                    std::cout << "Lesson: " << lessonName << " - Grade: " << grade.getGrade() << std::endl;
                }
            }
        }
    }
}

void updateStudentRecord(Student &student) {
    std::string newEmail, newPhoneNumber, newAddress;
    std::cout << "Enter the new email: ";
    std::cin >> newEmail;
    std::cout << "Enter the new phone number: ";
    std::cin >> newPhoneNumber;
    std::cout << "Enter the new address: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, newAddress);

    student.setEmail(newEmail);
    student.setPhoneNumber(newPhoneNumber);
    student.setAddress(newAddress);

    std::cout << "Student information has been updated successfully." << std::endl;
}


void updateGrade(const std::unordered_map<int, Student> &students,
                 std::unordered_map<int, Grade> &grades,
                 int studentID, int groupID, int lessonID, int newGrade) {
    bool gradeUpdated = false;

    auto studentIter = students.find(studentID);
    if (studentIter != students.end() && studentIter->second.getGroupID() == groupID) {
        for (auto &[id, grade]: grades) {
            if (grade.getStudentID() == studentID && grade.getLessonID() == lessonID) {
                grade.setGrade(newGrade);
                gradeUpdated = true;
                break;
            }
        }
    }

    if (gradeUpdated) {
        std::cout << "Grade has been updated successfully." << std::endl;
    } else {
        std::cout << "Grade not found or student not in the specified group." << std::endl;
    }
}


bool isInRange(int value, int min, int max) {
    if (value < min || value > max) {
        std::cout << "Invalid input. Please enter a number between " << min << " and " << max << "." << std::endl;
        return false;
    }
    return true;
}


int getMenuChoice(int min, int max) {
    int choice;
    while (true) {
        std::cout << "Please choose an option between " << min << " and " << max << ": ";
        std::cin >> choice;
        if (isInRange(choice, min, max)) {
            break;
        }
    }
    return choice;
}

std::unordered_map<int, Student> initStudents() {
    return {
            {1, Student(1, "John", "A.", "Smith", "john.smith@example.com", "+1 555-1234", "123 Main St, Anytown, USA",
                        101, 1, 1)},
            {2, Student(2, "Jane", "B.", "Doe", "jane.doe@example.com", "+1 555-5678", "456 High St, Anytown, USA", 101,
                        1, 1)},
            {3, Student(3, "Michael", "C.", "Johnson", "michael.johnson@example.com", "+1 555-9012",
                        "789 Oak Ave, Anytown, USA", 102, 1, 2)},
            {4, Student(4, "Emily", "D.", "Williams", "emily.williams@example.com", "+1 555-3456",
                        "321 Elm St, Anytown, USA", 102, 1, 2)}
    };
}

std::unordered_map<int, Group> initGroups() {
    return {
            {101, Group(101, "Group A")},
            {102, Group(102, "Group B")}
    };
}

std::unordered_map<int, Faculty> initFaculties() {
    return {
            {1, Faculty(1, "Engineering")},
            {2, Faculty(2, "Science")}
    };
}

std::unordered_map<int, Lesson> initLessons() {
    return {
            {1, Lesson(1, "Math")},
            {2, Lesson(2, "Physics")}
    };
}

std::unordered_map<int, Grade> initGrades() {
    return {
            {1, Grade(1, 1, 1, 5)},
            {2, Grade(2, 1, 2, 5)},
            {3, Grade(3, 2, 1, 4)},
            {4, Grade(4, 2, 2, 5)},
            {5, Grade(5, 3, 1, 5)},
            {6, Grade(6, 3, 2, 4)},
            {7, Grade(7, 4, 1, 5)},
            {8, Grade(8, 4, 2, 5)}
    };
}


int main() {
    try {
        std::unordered_map<int, Student> students = initStudents();

        std::unordered_map<int, Group> groups = initGroups();

        std::unordered_map<int, Faculty> faculties = initFaculties();

        std::unordered_map<int, Lesson> lessons = initLessons();

        std::unordered_map<int, Grade> grades = initGrades();

        Teacher teacher(1, "Alice", "E.", "Brown", "alice.brown@example.com", "+1 555-7890", "teacher1", "password123");


        if (!teacherLogin(teacher)) {
            std::cout << "Invalid login or password" << std::endl;
            return 1;
        }

        int choice;
        do {
            displayMenu();
            choice = getMenuChoice(1, 3);

            switch (choice) {
                case 1: {
                    std::string firstName, middleName, lastName;
                    std::cout << "Enter the student's first name: ";
                    std::cin >> firstName;
                    std::cout << "Enter the student's middle name: ";
                    std::cin >> middleName;
                    std::cout << "Enter the student's last name: ";
                    std::cin >> lastName;

                    int studentIndex = searchStudent(students, firstName, middleName, lastName);

                    if (studentIndex != -1) {
                        displayStudentInfo(students[studentIndex]);

                        char updateRecord;
                        std::cout << "Do you want to update any records? (y/n): ";
                        std::cin >> updateRecord;
                        if (updateRecord == 'y' || updateRecord == 'Y') {
                            updateStudentRecord(students[studentIndex]);
                        }
                    } else {
                        std::cout << "Student not found." << std::endl;
                    }
                }
                    break;

                case 2: {
                    std::string groupName;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Enter the group name: ";
                    getline(std::cin, groupName);

                    int groupID = findGroupID(groups, groupName);
                    if (groupID != -1) {
                        displayGroupStudentsAndGrades(students, grades, lessons, groupID);

                        char updateGradeChoice;
                        std::cout << "Do you want to update any grades? (y/n): ";
                        std::cin >> updateGradeChoice;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        if (updateGradeChoice == 'y' || updateGradeChoice == 'Y') {
                            int studentID, lessonID, newGrade;
                            std::cout << "Enter the student ID: ";
                            std::cin >> studentID;
                            std::cout << "Enter the lesson ID: ";
                            std::cin >> lessonID;
                            std::cout << "Enter the new grade: ";
                            std::cin >> newGrade;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            updateGrade(grades, studentID, lessonID, newGrade);
                        }
                    } else {
                        std::cout << "Group not found." << std::endl;
                    }
                }
                    break;

                case 3:
                    std::cout << "Goodbye!" << std::endl;
                    break;

                default:
                    std::cout << "Invalid choice, please try again." << std::endl;
            }

        } while (choice != 3);
    } catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return 1;
    }
    return 0;
}

