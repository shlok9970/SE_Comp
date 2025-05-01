/*Group D-Practical 9
Dictionary  stores  keywords  &  its  meanings.  Provide  facility  for  adding  new  keywords, deleting keywords, updating values of any entry.Also,display whole data sorted in ascending or descending order. Find how many maximum comparisons may require for finding any keyword. Use height balance tree and find the complexity for finding a keyword.*/

#include<iostream>
using namespace std;
struct avl_node {
   string keyword;
   string meaning;
   struct avl_node *left;
   struct avl_node *right;
}*root;
class avl_tree {
   public:
      int height(avl_node *);
      int difference(avl_node *);
      avl_node *rr_rotation(avl_node *);
      avl_node *ll_rotation(avl_node *);
      avl_node *lr_rotation(avl_node*);
      avl_node *rl_rotation(avl_node *);
      avl_node * balance(avl_node *);
      avl_node * insert(avl_node*, string, string);
      void display(avl_node*, int);
     
      avl_tree() {
         root = NULL;
      }
};
avl_node *avl_tree::insert(avl_node *root, string key, string meaning) {
   if (root == NULL) {
      root = new avl_node;
      root->keyword = key;
      root->meaning = meaning;
      root->left = NULL;
      root->right = NULL;
      return root;
   } else if (key < root->keyword) {
      root->left = insert(root->left, key, meaning);
      root = balance(root);
   } else if (key >= root->keyword) {
      root->right = insert(root->right, key, meaning);
      root = balance(root);
   }
   return root;
}

avl_node *avl_tree::balance(avl_node *temp) {
   int balance_factor = difference(temp);
   if (balance_factor > 1) {
      if (difference(temp->left) > 0)
         temp = ll_rotation(temp);
      else
         temp = lr_rotation(temp);
   } else if (balance_factor < -1) {
      if (difference(temp->right) > 0)
         temp = rl_rotation(temp);
      else
         temp = rr_rotation(temp);
   }
   return temp;
}
int avl_tree::height(avl_node *temp) {
   int h = 0;
   if (temp != NULL) {
      int l_height = height(temp->left);
      int r_height = height(temp->right);
      int max_height = max(l_height, r_height);
      h = max_height + 1;
   }
   return h;
}

int avl_tree::difference(avl_node *temp) {
   int l_height = height(temp->left);
   int r_height = height(temp->right);
   int balance_factor = l_height - r_height;
   return balance_factor;
}

avl_node *avl_tree::rr_rotation(avl_node *parent) {
   avl_node *temp;
   temp = parent->right;
   parent->right = temp->left;
   temp->left = parent;
   return temp;
}

avl_node *avl_tree::ll_rotation(avl_node *parent) {
   avl_node *temp;
   temp = parent->left;
   parent->left = temp->right;
   temp->right = parent;
   return temp;
}

avl_node *avl_tree::lr_rotation(avl_node *parent) {
   avl_node *temp;
   temp = parent->left;
   parent->left = rr_rotation(temp);
   return ll_rotation(parent);
}

avl_node *avl_tree::rl_rotation(avl_node *parent) {
   avl_node *temp;
   temp = parent->right;
   parent->right = ll_rotation(temp);
   return rr_rotation(parent);
}

void avl_tree::display(avl_node *ptr, int level) {
   int i;
   if (ptr != NULL) {
      display(ptr->left, level + 1);
      cout << endl;
      if (ptr == root)
         cout << "Root ->  ";
      for (i = 0; i < level && ptr != root; i++)
         cout << " ";
      cout << ptr->keyword << "(" << ptr->meaning << ")";
     
      display(ptr->right, level + 1);
   }
}

int main() {
   int choice;
   string key, meaning;
   avl_tree avl;
   while (1) {
      cout << "\n\tAVL Tree Operations\n\n";
      cout << "1. Insert Keyword and Meaning" << endl;
      cout << "2. Display Balanced AVL Tree" << endl;
      cout << "3. Exit" << endl;
      cout << "\nEnter your choice: ";
      cin >> choice;
      switch (choice) {
         case 1:
            cout << "\nEnter keyword: ";
            cin >> key;
            cout << "Enter meaning: ";
            cin.ignore(); // to clear the input buffer
            getline(cin, meaning);
            root = avl.insert(root, key, meaning);
            break;
         case 2:
            if (root == NULL) {
               cout << "Tree is Empty" << endl;
               continue;
            }
            cout << "Balanced AVL Tree:" << endl;
            avl.display(root, 1);
            break;
         case 3:
            exit(1);
            break;
         default:
            cout << "Invalid choice" << endl;
      }
   }
   return 0;
}

