#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float cgpa;
};

int main() {
    int n, searchId;

    cout << "Enter number of students: ";
    cin >> n;

    Student* students = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of Student " << i + 1 << endl;
        cout << "Enter ID: ";
        cin >> students[i].id;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, students[i].name);

        cout << "Enter CGPA: ";
        cin >> students[i].cgpa;
    }

    cout << "\nEnter Student ID to search: ";
    cin >> searchId;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (students[i].id == searchId) {
            cout << "\nStudent Found!\n"
                 << "ID   : " << students[i].id << '\n'
                 << "Name : " << students[i].name << '\n'
                 << "CGPA : " << students[i].cgpa << '\n';
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nStudent Not Found!\n";

    delete[] students;
    return 0;
}