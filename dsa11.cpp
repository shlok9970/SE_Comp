/*Group F-practical 11
Department maintains a student information. The file contains roll number, name, division and address. Allow user to add, delete information of student. 
Display information of particular student. If record of student does not exist an appropriate message is displayed. 
If it is, then the system displays the student details. Use sequential file to main the data.*/

#include<iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    string division;
    string address;
};

void addStudent() {
    Student s;
    ofstream fout("students.txt", ios::app);
    cout << "Enter roll number: ";
    cin >> s.roll;
    cout << "Enter name: ";
    cin >> s.name;
    cout << "Enter division: ";
    cin >> s.division;
    cin.ignore(); // Ignore leftover newline
    cout << "Enter address: ";
    getline(cin, s.address);

    fout << s.roll << " " << s.name << " " << s.division << " " << s.address << endl;
    fout.close();
    cout << "Student record added successfully.\n";
}

void displayAllStudents() {
    Student s;
    ifstream fin("students.txt");
    bool found = false;

    cout << "\n--- Student Records ---\n";
    while (fin >> s.roll >> s.name >> s.division) {
        fin.ignore(); // Skip the space before address
        getline(fin, s.address);
        cout << "Roll: " << s.roll
             << "\nName: " << s.name
             << "\nDivision: " << s.division
             << "\nAddress: " << s.address << "\n\n";
        found = true;
    }

    fin.close();
    if (!found) {
        cout << "No student records found.\n";
    }
}

void searchStudent() {
    int r;
    Student s;
    bool found = false;
    ifstream fin("students.txt");

    cout << "Enter roll number to search: ";
    cin >> r;

    while (fin >> s.roll >> s.name >> s.division) {
        fin.ignore(); // Skip space before address
        getline(fin, s.address);
        if (s.roll == r) {
            cout << "\n--- Student Found ---\n";
            cout << "Roll: " << s.roll
                 << "\nName: " << s.name
                 << "\nDivision: " << s.division
                 << "\nAddress: " << s.address << endl;
            found = true;
            break;
        }
    }

    fin.close();
    if (!found) {
        cout << "Student not found.\n";
    }
}

void deleteStudent() {
    int r;
    Student s;
    bool found = false;
    ifstream fin("students.txt");
    ofstream temp("temp.txt");

    cout << "Enter roll number to delete: ";
    cin >> r;

    while (fin >> s.roll >> s.name >> s.division) {
        fin.ignore(); // Skip space before address
        getline(fin, s.address);
        if (s.roll != r) {
            temp << s.roll << " " << s.name << " " << s.division << " " << s.address << endl;
        } else {
            found = true;
        }
    }

    fin.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "Student record deleted.\n";
    else
        cout << "Student not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n====== Student Management Menu ======\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAllStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

