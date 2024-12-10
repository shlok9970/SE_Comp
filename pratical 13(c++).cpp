#include <iostream>
using namespace std;

class Deque {
private:
    int* arr;       // Array to store deque elements
    int front;      // Index of the front element
    int rear;       // Index of the rear element
    int capacity;   // Maximum capacity of the deque
    int size;       // Current size of the deque

public:
    // Constructor to initialize the deque
    Deque(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = 0;
        size = 0;
    }

    // Destructor to free allocated memory
    ~Deque() {
        delete[] arr;
    }

    // Function to check if the deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to check if the deque is full
    bool isFull() {
        return size == capacity;
    }

    // Function to add an element at the front of the deque
    void addFront(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot add to front." << endl;
            return;
        }
        front = (front == -1) ? 0 : (front - 1 + capacity) % capacity; // Circular increment
        arr[front] = value;
        size++;
        if (rear == 0) {
            rear = front; // If the deque was empty, set rear to front
        }
        cout << "Added " << value << " to the front." << endl;
    }

    // Function to add an element at the rear of the deque
    void addRear(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot add to rear." << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Circular increment
        arr[rear] = value;
        size++;
        if (front == -1) {
            front = rear; // If the deque was empty, set front to rear
        }
        cout << "Added " << value << " to the rear." << endl;
    }

    // Function to delete an element from the front of the deque
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from front." << endl;
            return;
        }
        cout << "Deleted " << arr[front] << " from the front." << endl;
        front = (front + 1) % capacity; // Circular increment
        size--;
        if (size == 0) {
            front = -1; // Reset front and rear if deque is empty
            rear = 0;
        }
    }

    // Function to delete an element from the rear of the deque
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from rear." << endl;
            return;
        }
        cout << "Deleted " << arr[rear] << " from the rear." << endl;
        rear = (rear - 1 + capacity) % capacity; // Circular decrement
        size--;
        if (size == 0) {
            front = -1; // Reset front and rear if deque is empty
            rear = 0;
        }
    }

    // Function to display the elements of the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }
        cout << "Deque elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the deque: ";
    cin >> capacity;

    Deque deque(capacity);
    int choice, value;

    do {
        cout << "\nDeque Menu:" << endl;
        cout << "1. Add to Front" << endl;
        cout << "2. Add to Rear" << endl;
        cout << "3. Delete from Front" << endl;
        cout << "4. Delete from Rear" << endl;
        cout << "5. Display Deque" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add to front: ";
                cin >> value;
                deque.addFront(value);
                break;
            case 2:
                cout << "Enter value to add to rear: ";
                cin >> value;
                deque.addRear(value);
                break;
            case 3:
                deque.deleteFront();
                break;
            case 4:
                deque.deleteRear();
                break;
            case 5:
                deque.display();
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}