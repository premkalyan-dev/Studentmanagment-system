#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

vector<Student> students;

// Add a new student
void addStudent() {
    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.rollNo;

    // Check for duplicate roll number
    for (const auto& stu : students) {
        if (stu.rollNo == s.rollNo) {
            cout << "Roll Number already exists!\n";
            return;
        }
    }

    cout << "Enter Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s.name);
    cout << "Enter Marks: ";
    cin >> s.marks;

    students.push_back(s);
    cout << "Student added successfully.\n";
}

// Display all students
void displayStudents() {
    if (students.empty()) {
        cout << "No students to display.\n";
        return;
    }

    cout << "\n--- Student List ---\n";
    cout << "Roll No\tName\tMarks\n";
    for (const auto& s : students) {
        cout << s.rollNo << "\t" << s.name << "\t" << s.marks << "\n";
    }
}

// Search student by roll number
void searchStudent() {
    int roll;
    cout << "Enter Roll Number to Search: ";
    cin >> roll;

    for (const auto& s : students) {
        if (s.rollNo == roll) {
            cout << "Student Found: " << s.name << ", Marks: " << s.marks << endl;
            return;
        }
    }
    cout << "Student not found.\n";
}

// Update student details
void updateStudent() {
    int roll;
    cout << "Enter Roll Number to Update: ";
    cin >> roll;

    for (auto& s : students) {
        if (s.rollNo == roll) {
            cout << "Enter New Name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, s.name);
            cout << "Enter New Marks: ";
            cin >> s.marks;
            cout << "Student record updated.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

// Delete student record
void deleteStudent() {
    int roll;
    cout << "Enter Roll Number to Delete: ";
    cin >> roll;

    auto it = remove_if(students.begin(), students.end(),
                        [roll](const Student& s){ return s.rollNo == roll; });

    if (it != students.end()) {
        students.erase(it, students.end());
        cout << "Student deleted successfully.\n";
    } else {
        cout << "Student not found.\n";
    }
}

// Sort students by marks (descending)
void sortByMarks() {
    if (students.empty()) {
        cout << "No students to sort.\n";
        return;
    }

    sort(students.begin(), students.end(),
         [](const Student& a, const Student& b){ return a.marks > b.marks; });

    cout << "Students sorted by marks.\n";
    displayStudents();
}

// Calculate average marks
void averageMarks() {
    if (students.empty()) {
        cout << "No students to calculate average.\n";
        return;
    }

    float total = 0;
    for (const auto& s : students) total += s.marks;
    cout << "Average Marks: " << total / students.size() << endl;
}

int main() {
    int choice;

    do {
        cout << "\n--- Student Record System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Sort by Marks\n";
        cout << "7. Average Marks\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: sortByMarks(); break;
            case 7: averageMarks(); break;
            case 8: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
