#include <iostream>
#include <string>
using namespace std;

// Maximum number of students
const int MAX_STUDENTS = 100;

// Student Structure
struct Student {
    int rollNo;
    string name;
    float marks;
};

// Array to store students
Student students[MAX_STUDENTS];
int studentCount = 0;

// Function to add a new student
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Student limit reached!\n";
        return;
    }

    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.rollNo;
    cout << "Enter Name: ";
    cin.ignore();  // Clear buffer
    getline(cin, s.name);
    cout << "Enter Marks: ";
    cin >> s.marks;

    students[studentCount++] = s;
    cout << "Student added successfully.\n";
}

// Function to display all students
void displayStudents() {
    if (studentCount == 0) {
        cout << "No students to display.\n";
        return;
    }

    cout << "\n--- Student List ---\n";
    for (int i = 0; i < studentCount; i++) {
        cout << "Roll No: " << students[i].rollNo
             << ", Name: " << students[i].name
             << ", Marks: " << students[i].marks << endl;
    }
}

// Function to search student by roll number
void searchStudent() {
    int roll;
    cout << "Enter Roll Number to Search: ";
    cin >> roll;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == roll) {
            cout << "Student Found: " << students[i].name
                 << ", Marks: " << students[i].marks << endl;
            return;
        }
    }
    cout << "Student not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- Student Record System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}