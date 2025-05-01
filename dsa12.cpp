/*Group F-practical 12

Company maintains employee information as employee ID, name, designation and salary. 
Allow user to add, delete information of employee. Display information of particular 
employee. If employee does not exist an appropriate message is displayed. If it is, then 
the system displays the employee details. Use index sequential file to maintain the data.
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

// Structure to hold employee information
struct Employee {
    int id;
    string name;
    string designation;
    float salary;
};

// Function to build index from file
void createIndex(map<int, streampos>& index) {
    index.clear();
    ifstream fin("employees.txt");
    Employee e;
    streampos pos;

    while (fin) {
        pos = fin.tellg();		//current file pointer
        if (fin >> e.id >> e.name >> e.designation >> e.salary) {
            index[e.id] = pos;
        }
        // Skip to next line to prevent infinite loop on malformed lines
        //fin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    fin.close();
}

// Add employee to the file
void addEmployee() {
    Employee e;
    ofstream fout("employees.txt", ios::app);
    
    cout << "Enter ID: ";
    cin >> e.id;
    cout << "Enter name: ";
    cin >> e.name;
    cout << "Enter designation: ";
    cin >> e.designation;
    cout << "Enter salary: ";
    cin >> e.salary;

    fout << e.id << " " << e.name << " " << e.designation << " " << e.salary << endl;
    fout.close();

    cout << "Employee added successfully.\n";
}

// Display details of a particular employee
void displayEmployee(const map<int, streampos>& index) {
    int id;
    Employee e;
    cout << "Enter employee ID to search: ";
    cin >> id;

    ifstream fin("employees.txt");
    if (index.find(id) != index.end()) {
        fin.seekg(index.at(id));		//moves file pointer to the employee record.
        fin >> e.id >> e.name >> e.designation >> e.salary;

        cout << "\n--- Employee Found ---\n";
        cout << "ID: " << e.id << "\nName: " << e.name
             << "\nDesignation: " << e.designation
             << "\nSalary: " << e.salary << endl;
    } else {
        cout << "Employee not found.\n";
    }

    fin.close();
}

// Delete an employee from the file
void deleteEmployee(map<int, streampos>& index) {
    int id;
    Employee e;
    bool found = false;

    cout << "Enter employee ID to delete: ";
    cin >> id;

    ifstream fin("employees.txt");
    ofstream temp("temp.txt");

    while (fin >> e.id >> e.name >> e.designation >> e.salary) {
        if (e.id != id) {
            temp << e.id << " " << e.name << " " << e.designation << " " << e.salary << endl;
        } else {
            found = true;
        }
      //  fin.ignore(numeric_limits<streamsize>::max(), '\n'); // move to next line
    }

    fin.close();
    temp.close();

    remove("employees.txt");
    rename("temp.txt", "employees.txt");

    if (found) {
        cout << "Employee deleted successfully.\n";
        createIndex(index); // Refresh index
    } else {
        cout << "Employee not found.\n";
    }
}

// Main menu function
int main() {
    int ch;
    map<int, streampos> index;
    createIndex(index); // Initial index creation

    do {
        cout << "\n====== Employee Management Menu ======\n";
        cout << "1. Add Employee\n";
        cout << "2. Display Employee\n";
        cout << "3. Delete Employee\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                addEmployee();
                createIndex(index); // Refresh index after adding
                break;

            case 2:
                displayEmployee(index);
                break;

            case 3:
                deleteEmployee(index);
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (ch != 4);

    return 0;
}

