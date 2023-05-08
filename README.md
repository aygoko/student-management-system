# Student Management System

The Student Management System is a C++ console application that allows teachers to manage students, review their grades, and update records. 

This program is implemented using various classes and functions to handle the data and operations efficiently.

## Prerequisites

- A C++ compiler with support for C++23 (e.g., GCC, Clang, or Visual Studio)
- This application requires a C++ compiler with support for C++17 and the [nlohmann/json](https://github.com/nlohmann/json) library

## How to Compile and Run

### Using CMake

1. Clone or download the repository.
2. Ensure that the nlohmann/json library is installed and included in your compiler's search path.
3. Create a build directory in the project root:

   `mkdir build`

   `cd build`
4. Run CMake and compile the project:
   ```bash 
   cmake ..
   cmake --build .
   ```
5. Run the generated executable file (named `your_project_name` or `your_project_name.exe` on Windows):

`./your_project_name`
## Example Commands
### 1. Logging in as a teacher 

```
Enter your login: teacher1
Enter your password: password123
```

### 2. Searching for a student
```Please choose an option between 1 and 3: 1
Enter the student's first name: John
Enter the student's middle name: A.
Enter the student's last name: Smith
```

### 3. Updating a student's record:
```Do you want to update any records? (y/n): y
Enter the new email: john.newemail@example.com
Enter the new phone number: +1 555-9876
Enter the new address: 789 Pine St, Anytown, USA
```
### 4. Reviewing grades for a group
```Please choose an option between 1 and 3: 2
Enter the group name: Group A
``` 
### 5. Updating a grade for a student
```Do you want to update any grades? (y/n): y
Enter the student ID: 1
Enter the lesson ID: 1
Enter the new grade: 4
```
### 6. Exiting the application
```
Please choose an option between 1 and 3: 3
Goodbye!
```


To run the Student Management System, simply compile and execute the main source file. Follow the on-screen prompts to perform various actions related to managing students and their grades.

## Project structure

```js
student_management_system /
    ├── Headers/
    │   ├── Student.h
    │   ├── Faculty.h
    │   ├── Group.h
    │   ├── Grade.h
    │   ├── Lesson.h
    ├── Sources/
    │   ├── main.cpp
    │   └── src/
    │       ├── Student.cpp
    │       ├── Faculty.cpp
    │       ├── Group.cpp
    │       ├── Grade.cpp
    │       └── Lesson.cpp
    └── CMakeLists.txt     
    └── students.json       
    └── grades.json
   
```
