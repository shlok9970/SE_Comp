/*To create ADT that implement the "set" concept.
a. Add (new Element) -Place a value into the set , b. Remove (element) Remove the
value
c. Contains (element) Return true if element is in collection, d. Size () Return number of
values in collection Iterator () Return an iterator used to loop over collection, e.
Intersection of two sets , f. Union of two sets, g. Difference between two sets, h. Subset*/

#include<iostream>
using namespace std;

class set_operations {
public:
    void Union(int set1[], int set2[], int size1, int size2) {
        int result[100], k = 0;

        for (int i = 0; i < size1; i++) {
            result[k++] = set1[i];
        }

        for (int i = 0; i < size2; i++) {
            bool found = false;
            for (int j = 0; j < size1; j++) {
                if (set2[i] == set1[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result[k++] = set2[i];
            }
        }

        cout << "\nUnion of Set 1 and Set 2: ";
        for (int i = 0; i < k; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    void Intersection(int set1[], int set2[], int size1, int size2) {
        int result[100], k = 0;

        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                if (set1[i] == set2[j]) {
                    bool already_added = false;
                    for (int m = 0; m < k; m++) {
                        if (result[m] == set1[i]) {
                            already_added = true;
                            break;
                        }
                    }
                    if (!already_added) {
                        result[k++] = set1[i];
                    }
                }
            }
        }

        cout << "\nIntersection of Set 1 and Set 2: ";
        for (int i = 0; i < k; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

 void Difference(int set1[], int set2[], int size1, int size2) {
    int result[100], k = 0;

    for (int i = 0; i < size1; i++) {
        bool found = false;
        for (int j = 0; j < size2; j++) {
            if (set1[i] == set2[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result[k++] = set1[i];
        }
    }

    if (k == 0) {
        cout << "\nNo elements found in the difference (Set1 - Set2)." << endl;
    } else {
        cout << "\nDifference (Set1 - Set2): ";
        for (int i = 0; i < k; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
}

    void IsSubset(int set1[], int set2[], int size1, int size2) {
        bool isSubset = true;

        for (int i = 0; i < size1; i++) {
            bool found = false;
            for (int j = 0; j < size2; j++) {
                if (set1[i] == set2[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                isSubset = false;
                break;
            }
        }

        if (isSubset)
            cout << "\nSet1 is a subset of Set2." << endl;
        else
            cout << "\nSet1 is NOT a subset of Set2." << endl;
    }
};

int main() {
    int set1[10], set2[10], size1, size2, choice;
    set_operations s;

    cout << "Enter number of elements in Set 1: ";
    cin >> size1;
    for (int i = 0; i < size1; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> set1[i];
    }

    cout << "\nEnter number of elements in Set 2: ";
    cin >> size2;
    for (int i = 0; i < size2; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> set2[i];
    }

    do {
        cout << "\n----- Set Operations Menu -----";
        cout << "\n1. Union";
        cout << "\n2. Intersection";
        cout << "\n3. Difference (Set1 - Set2)";
        cout << "\n4. Subset Check (Is Set1 subset of Set2)";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.Union(set1, set2, size1, size2);
                break;
            case 2:
                s.Intersection(set1, set2, size1, size2);
                break;
            case 3:
                s.Difference(set1, set2, size1, size2);
                break;
            case 4:
                s.IsSubset(set1, set2, size1, size2);
                break;
            case 5:
                cout << "\nExiting program." << endl;
                break;
            default:
                cout << "\nInvalid choice! Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}

