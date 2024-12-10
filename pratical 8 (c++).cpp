#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// Node structure for linked list
struct Node {
    string name;
    Node* next;

    Node(string n) : name(n), next(nullptr) {}
};

// Class for linked list
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to insert a student into the linked list
    void insert(const string& name) {
        Node* newNode = new Node(name);
        newNode->next = head;
        head = newNode;
    }

    // Function to display the linked list
    void display() {
        Node* current = head;
        while (current) {
            cout << current->name << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Function to get the names in a set for easy comparison
    unordered_set<string> toSet() {
        unordered_set<string> studentSet;
        Node* current = head;
        while (current) {
            studentSet.insert(current->name);
            current = current->next;
        }
        return studentSet;
    }

    // Getter for head (for internal use)
    Node* getHead() {
        return head;
    }
};

// Function to compute the intersection of two sets
LinkedList intersection(LinkedList& a, LinkedList& b) {
    LinkedList result;
    unordered_set<string> setB = b.toSet();
    Node* current = a.getHead();

    while (current) {
        if (setB.find(current->name) != setB.end()) {
            result.insert(current->name);
        }
        current = current->next;
    }
    return result;
}

// Function to compute the union of two sets
LinkedList unionSet(LinkedList& a, LinkedList& b) {
    LinkedList result;
    unordered_set<string> studentSet;

    Node* current = a.getHead();
    while (current) {
        studentSet.insert(current->name);
        current = current->next;
    }

    current = b.getHead();
    while (current) {
        studentSet.insert(current->name);
        current = current->next;
    }

    for (const auto& name : studentSet) {
        result.insert(name);
    }
    return result;
}

// Function to compute the symmetric difference of two sets
LinkedList symmetricDifference(LinkedList& a, LinkedList& b) {
    LinkedList result;
    unordered_set<string> setA = a.toSet();
    unordered_set<string> setB = b.toSet();

    for (const auto& name : setA) {
        if (setB.find(name) == setB.end()) {
            result.insert(name);
        }
    }

    for (const auto& name : setB) {
        if (setA.find(name) == setA.end()) {
            result.insert(name);
        }
    }

    return result;
}

// Function to count students who like neither
int countNeither(LinkedList& a, LinkedList& b, const unordered_set<string>& allStudents) {
    unordered_set<string> setA = a.toSet();
    unordered_set<string> setB = b.toSet();
    int count = 0;

    for (const auto& student : allStudents) {
        if (setA.find(student) == setA.end() && setB.find(student) == setB.end()) {
            count++;
        }
    }
    return count;
}

int main() {
    LinkedList vanillaStudents;
    LinkedList butterscotchStudents;

    // Input for Vanilla students
    int n;
    cout << "Enter number of students who like Vanilla ice-cream: ";
    cin >> n;
    cout << "Enter names of students who like Vanilla ice-cream:\n";
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        vanillaStudents.insert(name);
    }

    // Input for Butterscotch students
    cout << "Enter number of students who like Butterscotch ice-cream: ";
    cin >> n;
    cout << "Enter names of students who like Butterscotch ice-cream :\n";
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        butterscotchStudents.insert(name);
    }

    // Display both sets
    cout << "Students who like Vanilla: ";
    vanillaStudents.display();
    cout << "Students who like Butterscotch: ";
    butterscotchStudents.display();

    // Compute and display the set of students who like both
    LinkedList bothStudents = intersection(vanillaStudents, butterscotchStudents);
    cout << "Students who like both Vanilla and Butterscotch: ";
    bothStudents.display();

    // Compute and display the set of students who like either or not both
    LinkedList eitherStudents = symmetricDifference(vanillaStudents, butterscotchStudents);
    cout << "Students who like either Vanilla or Butterscotch or not both: ";
    eitherStudents.display();

    // Count and display the number of students who like neither
    unordered_set<string> allStudents; // Assuming we have a list of all students
    cout << "Enter total number of students in the class: ";
    cin >> n;
    cout << "Enter names of all students in the class:\n";
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        allStudents.insert(name);
    }

    int neitherCount = countNeither(vanillaStudents, butterscotchStudents, allStudents);
    cout << "Number of students who like neither Vanilla nor Butterscotch: " << neitherCount << endl;

    return 0;
}