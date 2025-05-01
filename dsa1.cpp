/*Consider telephone book database of N clients. Make use of a hash table
implementation to quickly look up client‘s telephone number. Make use of two collision
handling techniques and compare them using number of comparisons required to find a
set of telephone numbers*/

#include<iostream>
using namespace std;

class node {
    string name;
    int id;
    long int tel;
    friend class hashing;
public:
    node() {
        id = 0;
        tel = 0;
    }
};

class hashing {
    node data[100];
    int index;
public:
    void create_record(int size, string n, int i, long int t) {
        index = i % size;
        for (int j = 0; j < size; j++) {
            if (data[index].id == 0) {
                data[index].name = n;
                data[index].id = i;
                data[index].tel = t;
                cout << "Record added successfully!" << endl;
                return;
            } else {
                index = (index + 1) % size;
            }
        }
        cout << "Hash table is full. Record could not be added." << endl;
    }

    void display(int size) {
        for (int i = 0; i < size; i++) {
            if (data[i].id != 0) {
                cout << "\nID = " << data[i].id << endl;
                cout << "Name = " << data[i].name << endl;
                cout << "Telephone No. = " << data[i].tel << endl;
            }
        }
    }

    void search(int size, int i) {
        index = i % size;
        for (int j = 0; j < size; j++) {
            if (data[index].id == i) {
                cout << "ID found at " << index << " location" << endl;
                cout << "\nID = " << data[index].id << endl;
                cout << "Name = " << data[index].name << endl;
                cout << "Telephone No. = " << data[index].tel << endl;
                return;
            } else {
                index = (index + 1) % size;
            }
        }
        cout << "ID not found!" << endl;
    }

    void modify(int size, int i, string new_name, long int new_tel) {
        index = i % size;
        for (int j = 0; j < size; j++) {
            if (data[index].id == i) {
                data[index].name = new_name;
                data[index].tel = new_tel;
                cout << "Record modified successfully!" << endl;
                return;
            }
            index = (index + 1) % size;
        }
        cout << "Record not found!" << endl;
    }

    void delete_record(int size, int i) {
        index = i % size;
        for (int j = 0; j < size; j++) {
            if (data[index].id == i) {
                data[index].id = 0;
                data[index].name = "";
                data[index].tel = 0;
                cout << "Record deleted successfully!" << endl;
                return;
            }
            index = (index + 1) % size;
        }
        cout << "Record not found!" << endl;
    }
};

int main() {
    int choice;
    int size = 10;
    string n;
    int i;
    long int t;
    hashing h;
    do {
        cout << "\nPHONE DIRECTORY\n1. Create Record\n2. Display Directory\n3. Search Telephone No.\n4. Modify Record\n5. Delete Record\n6. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Name: ";
            getline(cin >> ws, n);
            cout << "Enter ID: ";
            cin >> i;
            cout << "Enter Telephone No.: ";
            cin >> t;
            h.create_record(size, n, i, t);
            break;

        case 2:
            h.display(size);
            break;

        case 3:
            cout << "Enter ID to Search: ";
            cin >> i;
            h.search(size, i);
            break;

        case 4:
            cout << "Enter ID to Modify: ";
            cin >> i;
            cout << "Enter New Name: ";
            getline(cin >> ws, n);
            cout << "Enter New Telephone No.: ";
            cin >> t;
            h.modify(size, i, n, t);
            break;

        case 5:
            cout << "Enter ID to Delete: ";
            cin >> i;
            h.delete_record(size, i);
            break;

        case 6:
            cout << "EXIT" << endl;
            break;

        default:
            cout << "Invalid Choice" << endl;
        }
    } while (choice != 6);

    return 0;
}

