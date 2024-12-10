#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Node structure for doubly linked list
struct Node {
    char data; // Store binary digit (0 or 1)
    Node* next;
    Node* prev;

    Node(char d) : data(d), next(nullptr), prev(nullptr) {}
};

// Class for the doubly linked list
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to insert a binary digit at the end
    void insert(char data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to display the binary number
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data;
            current = current->next;
        }
        cout << endl;
    }

    // Function to compute 1's complement
    void onesComplement() {
        Node* current = head;
        while (current) {
            current->data = (current->data == '0') ? '1' : '0';
            current = current->next;
        }
    }

    // Function to compute 2's complement
    void twosComplement() {
        onesComplement(); // First compute 1's complement
        addOne();         // Then add 1
    }

    // Function to compute 5's complement
    void fivesComplement() {
        // 5's complement is not standard for binary numbers,
        // but we can define it as 5 - binary number in decimal.
        // For simplicity, we will just display the 5's complement in binary.
        // This is a placeholder for a more complex implementation.
        cout << "5's complement is not directly computable in binary." << endl;
    }

    // Function to add 1 to the binary number
    void addOne() {
        Node* current = tail;
        int carry = 1; // We are adding 1

        while (current && carry) {
            if (current->data == '1') {
                current->data = '0'; // 1 + 1 = 0 with carry
            } else {
                current->data = '1'; // 0 + 1 = 1, no carry
                carry = 0; // No more carry
            }
            current = current->prev;
        }

        // If carry is still 1, we need to add a new node at the front
        if (carry) {
            insert('1');
        }
    }

    // Function to add two binary numbers
    static DoublyLinkedList addBinary(DoublyLinkedList& a, DoublyLinkedList& b) {
        DoublyLinkedList result;
        Node* p1 = a.tail;
        Node* p2 = b.tail;
        int carry = 0;

        while (p1 || p2 || carry) {
            int sum = carry;
            if (p1) {
                sum += (p1->data - '0'); // Convert char to int
                p1 = p1->prev;
            }
            if (p2) {
                sum += (p2->data - '0'); // Convert char to int
                p2 = p2->prev;
            }

            carry = sum / 2; // Calculate carry
            result.insert((sum % 2) + '0'); // Insert the result bit
        }

        // Reverse the result list to get the correct order
        Node* current = result.head;
        Node* prev = nullptr;
        while (current) {
            Node* next = current->next;
            current->next = prev;
            current->prev = next;
            prev = current;
            current = next;
        }
        result.head = prev;

        return result;
    }
};

int main() {
    DoublyLinkedList binaryNumber;

    // Input binary number
    string input;
    cout << "Enter a binary number: ";
    cin >> input;

    for (char c : input) {
        binaryNumber.insert(c);
    }

    cout << "Original binary number: ";
    binaryNumber.display();

    // Compute 1's complement
    binaryNumber.onesComplement();
    cout << "1's complement: ";
    binaryNumber.display();

   }
