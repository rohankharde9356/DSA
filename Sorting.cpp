#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float cgpa;
};

int main() {
    int n, choice;

    cout << "Enter number of students: ";
    cin >> n;

    Student* s = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << '\n';
        cout << "Enter ID: ";
        cin >> s[i].id;
        cout << "Enter Name: ";
        cin >> s[i].name;
        cout << "Enter CGPA: ";
        cin >> s[i].cgpa;
    }

    cout << "\n1. Sort by Name (Alphabetical)";
    cout << "\n2. Sort by CGPA (Descending)";
    cout << "\nEnter your choice: ";
    cin >> choice;

    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            bool swapNeeded =
                (choice == 1 && s[j].name > s[j + 1].name) ||
                (choice == 2 && s[j].cgpa < s[j + 1].cgpa);

            if (swapNeeded) {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    cout << "\nSorted Student Records:\nID\tName\tCGPA\n";
    for (int i = 0; i < n; i++)
        cout << s[i].id << '\t' << s[i].name << '\t' << s[i].cgpa << '\n';

    delete[] s;
    return 0;
}