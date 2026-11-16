#include <iostream>
#include <cstdlib>
using namespace std;

struct Student {
    int id;
    char name[50];
    float cgpa;
};

int main() {
    int n, key;
    Student* s = nullptr;

    cout << "Number of students: ";
    cin >> n;

    s = (Student*)realloc(s, n * sizeof(Student));
    if (s == nullptr && n > 0) return 1;

    for (int i = 0; i < n; i++) {
        cout << "Enter ID, name, and CGPA for student " << i + 1 << ": ";
        cin >> s[i].id >> s[i].name >> s[i].cgpa;
    }

    // Sort students by ID
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (s[i].id > s[j].id) {
                Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }

    cout << "ID to search: ";
    cin >> key;

    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (s[mid].id == key) {
            cout << "Student found: " << s[mid].id << " "
                 << s[mid].name << " " << s[mid].cgpa << '\n';
            free(s);
            return 0;
        }

        if (s[mid].id < key) low = mid + 1;
        else high = mid - 1;
    }

    cout << "Student not found\n";
    free(s);
    return 0;
}