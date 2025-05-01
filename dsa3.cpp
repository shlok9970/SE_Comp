/*A book consists of chapters, chapters consist of sections and sections consist of
subsections. Construct a tree and print the nodes. Find the time and space requirements
of your method.*/

#include<iostream>
using namespace std;

struct node {
    char label[20];
    int ch_count;
    struct node* child[10];
} *root;

class GT {
public:
    GT() {
        root = NULL;
    }

    void create_tree() {
        int tchapters, tsections, tsub, i, j, k;
        root = new node;
        cout << "Enter the Name of the Book: ";
        cin >> root->label;

        cout << "Enter the number of chapters in " << root->label << " : ";
        cin >> tchapters;
        root->ch_count = tchapters;

        for (i = 0; i < tchapters; i++) {
            root->child[i] = new node;
            cout << "Enter the chapter " << i + 1 << " name: ";
            cin >> root->child[i]->label;

            cout << "Enter the number of sections in " << root->child[i]->label << " : ";
            cin >> tsections;
            root->child[i]->ch_count = tsections;

            for (j = 0; j < tsections; j++) {
                root->child[i]->child[j] = new node;
                cout << "Enter section " << j + 1 << " name: ";
                cin >> root->child[i]->child[j]->label;

                cout << "Enter number of subsections in " << root->child[i]->child[j]->label << " : ";
                cin >> tsub;
                root->child[i]->child[j]->ch_count = tsub;

                for (k = 0; k < tsub; k++) {
                    root->child[i]->child[j]->child[k] = new node;
                    cout << "Enter sub-section " << k + 1 << " name: ";
                    cin >> root->child[i]->child[j]->child[k]->label;
                    root->child[i]->child[j]->child[k]->ch_count = 0; // No further children
                }
            }
        }
    }

    void display(node* r1) {
        int i, j, k;

        if (r1 != NULL) {
            cout << "\n\n.....BOOK HIERARCHY.....\n";
            cout << "Book: " << r1->label << endl;

            for (i = 0; i < r1->ch_count; i++) {
                cout << "\n  Chapter " << i + 1 << ": " << r1->child[i]->label;

                for (j = 0; j < r1->child[i]->ch_count; j++) {
                    cout << "\n    Section " << j + 1 << ": " << r1->child[i]->child[j]->label;

                    for (k = 0; k < r1->child[i]->child[j]->ch_count; k++) {
                        cout << "\n      Sub-section " << k + 1 << ": " << r1->child[i]->child[j]->child[k]->label;
                    }
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int ch;
    GT obj;

    while (true) {
        cout << "\n\n...BOOK TREE MENU...\n";
        cout << "1. Create Book Tree\n";
        cout << "2. Display Book Tree\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                obj.create_tree();
                break;
            case 2:
                obj.display(root);
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}

