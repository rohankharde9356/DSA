#include <iostream>
using namespace std;

const int SIZE = 5;

class CircularQueue {
    int arr[SIZE], front = -1, rear = -1;

public:
    void enqueue(int value) {
        if ((rear + 1) % SIZE == front) {
            cout << "Queue is FULL!\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        cout << "Inserted: " << value << '\n';
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is EMPTY!\n";
            return;
        }
        cout << "Deleted: " << arr[front] << '\n';
        if (front == rear) front = rear = -1;
        else front = (front + 1) % SIZE;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is EMPTY!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; ; i = (i + 1) % SIZE) {
            cout << arr[i] << " ";
            if (i == rear) break;
        }
        cout << '\n';
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n1.Enqueue  2.Dequeue  3.Display  4.Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Value: ";
            cin >> value;
            q.enqueue(value);
        } else if (choice == 2) q.dequeue();
        else if (choice == 3) q.display();
    } while (choice != 4);
}