#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int id;
    int chinese;
    int math;
    int english;
    int total;
};

bool compareStudents(const Student& s1, const Student& s2) {
    if (s1.total != s2.total)
        return s1.total > s2.total;
    if (s1.chinese != s2.chinese)
        return s1.chinese > s2.chinese;
    return s1.id < s2.id;
}

int main() {
    vector<Student> students;
    int option;

    do {
        cout << "Welcome to Student Management System\n"
            << "1. Add a student\n"
            << "2. Remove a student\n"
            << "3. Query\n"
            << "4. Show the student list\n"
            << "5. Exit\n"
            << "Select an option: ";
        cin >> option;

        switch (option) {
        case 1: {
            Student newStudent;
            cout << "Enter student id, Chinese, Math, and English scores: ";
            cin >> newStudent.id >> newStudent.chinese >> newStudent.math >> newStudent.english;
            newStudent.total = newStudent.chinese + newStudent.math + newStudent.english;
            students.push_back(newStudent);
            break;
        }
        case 2: {
            int removeId;
            cout << "Enter student id to remove: ";
            cin >> removeId;
            auto it = find_if(students.begin(), students.end(), [removeId](const Student& s) { return s.id == removeId; });
            if (it != students.end())
                students.erase(it);
            else
                cout << "Student not found!" << endl;
            break;
        }
        case 3: {
            int queryId;
            cout << "Enter student id to query: ";
            cin >> queryId;
            auto it = find_if(students.begin(), students.end(), [queryId](const Student& s) { return s.id == queryId; });
            if (it != students.end()) {
                cout << "ID: " << it->id << ", Chinese: " << it->chinese << ", Math: " << it->math << ", English: " << it->english << ", Total: " << it->total << endl;
            }
            else {
                cout << "Student not found!" << endl;
            }
            break;
        }
        case 4: {
            if (students.empty()) {
                cout << "No students in the list" << endl;
            }
            else {
                sort(students.begin(), students.end(), compareStudents);
                for (const auto& student : students) {
                    cout << "ID: " << student.id << ", Chinese: " << student.chinese << ", Math: " << student.math << ", English: " << student.english << ", Total: " << student.total << endl;
                }
            }
            break;
        }
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid option! Please select again." << endl;
        }
    } while (option != 5);

    return 0;
}
