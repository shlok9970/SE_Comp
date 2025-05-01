/*Beginning with an empty binary search tree, Construct binary search tree by inserting
the values in the order given. After constructing a binary tree -
i. Insert new node, ii. Find number of nodes in longest path from root, iii. Minimum data
value found in the tree, iv. Change a tree so that the roles of the left and right pointers
are swapped at every node, v. Search a value*/


#include<iostream>
using namespace std;

class node {
public:
    int info;
    node* left;
    node* right;

    node(int val) {
        info = val;
        left = right = NULL;
    }
};

class BST {
public:
    node* root;

    BST() {
        root = NULL;
    }

    // Function to insert a new node in the BST
    void insert(node* &tree, int value) {
        if (tree == NULL) {
            tree = new node(value);
            cout << "Node with value " << value << " inserted." << endl;
            return;
        }
        if (value < tree->info) {
            insert(tree->left, value);
        }
        else if (value > tree->info) {
            insert(tree->right, value);
        }
        else {
            cout << "Value already exists in the tree!" << endl;
        }
    }

    // Function to find the height (longest path) of the tree
    int height(node* tree) {
        if (tree == NULL) return 0;
        int leftHeight = height(tree->left);
        int rightHeight = height(tree->right);
        return max(leftHeight, rightHeight) + 1;
    }

    // Function to find the minimum value in the tree
    int findMin(node* tree) {
        if (tree == NULL) {
            cout << "Tree is empty!" << endl;
            return -1; // Error value
        }
        while (tree->left != NULL) {
            tree = tree->left;
        }
        return tree->info;
    }

    // Function to swap the left and right pointers at every node
    void mirror(node* tree) {
        if (tree == NULL) return;
        swap(tree->left, tree->right);
        mirror(tree->left);
        mirror(tree->right);
    }

    // Function to search for a value in the tree
    bool search(node* tree, int value) {
        if (tree == NULL) return false;
        if (tree->info == value) return true;
        else if (value < tree->info) return search(tree->left, value);
        else return search(tree->right, value);
    }

    // Display tree in In-Order Traversal (for visualization purposes)
    void inorder(node* tree) {
        if (tree != NULL) {
            inorder(tree->left);
            cout << tree->info << " ";
            inorder(tree->right);
        }
    }
};

int main() {
    BST obj;
    int choice, value;

    do {
        cout << "\n--- Binary Search Tree Operations ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Find Height of Tree\n";
        cout << "3. Find Minimum Value\n";
        cout << "4. Mirror Tree\n";
        cout << "5. Search for a Value\n";
        cout << "6. Display Tree (In-Order)\n";
        cout << "7. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "\nEnter value to insert: ";
                cin >> value;
                obj.insert(obj.root, value);
                break;

            case 2:
                cout << "Height of the tree (longest path): " << obj.height(obj.root) << endl;
                break;

            case 3:
                cout << "Minimum value in the tree: " << obj.findMin(obj.root) << endl;
                break;

            case 4:
                obj.mirror(obj.root);
                cout << "Tree after mirroring (In-Order): ";
                obj.inorder(obj.root);
                cout << endl;
                break;

            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                if (obj.search(obj.root, value)) {
                    cout << "Value " << value << " found in the tree." << endl;
                } else {
                    cout << "Value " << value << " not found in the tree." << endl;
                }
                break;

            case 6:
                cout << "Tree in In-Order Traversal: ";
                obj.inorder(obj.root);
                cout << endl;
                break;

            case 7:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

