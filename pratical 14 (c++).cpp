#include <iostream>
#include <string>
using namespace std;

class CircularQueue {
private:
    string* orders; // Array to store orders
    int front;      // Index of the front order
    int rear;       // Index of the rear order
    int capacity;   // Maximum capacity of the queue
    int size;       // Current size of the queue

public:
    // Constructor to initialize the circular queue
    CircularQueue(int cap) {
        capacity = cap;
        orders = new string[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Destructor to free allocated memory
    ~CircularQueue() {
        delete[] orders;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Function to place an order
    void placeOrder(const string& order) {
        if (isFull()) {
            cout << "Order queue is full. Cannot place new order." << endl;
            return;
        }
        if (front == -1) {
            front = 0; // Set front to 0 if it's the first order
        }
        rear = (rear + 1) % capacity; // Circular increment
        orders[rear] = order; // Add the order
        size++;
        cout << "Order placed: " << order << endl;
    }

    // Function to serve an order
    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve." << endl;
            return;
        }
        cout << "Serving order: " << orders[front] << endl;
        front = (front + 1) % capacity; // Circular increment
        size--;
        if (isEmpty()) {
            front = -1; // Reset front and rear if queue is empty
            rear = -1;
        }
    }

    // Function to display current orders
    void displayOrders() {
        if (isEmpty()) {
            cout << "No current orders." << endl;
            return;
        }
        cout << "Current orders in the queue: ";
        for (int i = 0; i < size; i++) {
            cout << orders[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the maximum number of orders the pizza parlor can accept: ";
    cin >> capacity;

    CircularQueue orderQueue(capacity);
    int choice;
    string order;

    do {
        cout << "\nPizza Parlor Menu:" << endl;
        cout << "1. Place Order" << endl;
        cout << "2. Serve Order" << endl;
        cout << "3. Display Current Orders" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the order: ";
                cin.ignore(); // Clear the newline character from the input buffer
                getline(cin, order); // Read the order
                orderQueue.placeOrder(order); // Place the order
                break;
            case 2:
                orderQueue.serveOrder(); // Serve an order
                break;
            case 3:
                orderQueue.displayOrders(); // Display current orders
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}