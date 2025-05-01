#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    
    Node(char value) {
        data = value;
        left = right = nullptr;
    }
};
class Tree {
	
public:
	Node* root;
	Tree(){ 
		root = nullptr; 
	}
	void BuildExpression(const char *prefix)
	{
	Node *stack[50];
	int top = -1;
    
    for(int i=strlen(prefix)-1;i>=0;i--)
    {
    		if(isalpha(prefix[i]))
    		{
    			stack[++top]= new Node(prefix[i]);
    		}
    		else
    		{
    			Node *node=new Node(prefix[i]);
    			node->left=stack[top--];
    			node->right=stack[top--];
    			stack[++top]=node;
    		}
    }
      root=stack[top];                                             
	}

	void DisplayPostfix(Node *node)
	{
		if(!node) return;
		DisplayPostfix(node->left);
		DisplayPostfix(node->right);
		cout<<node->data;
	}

	void DeleteTree(Node* node) 
	{
        if (!node) return;
        DeleteTree(node->left);
        DeleteTree(node->right);
        cout<<"Deleting node :"<<node->data<<endl;
        delete node;
	}	

};

int main(){
	Tree tree;
	char prefix[10];
	cout<<"Enter Prefix Expression: ";
	cin>>prefix;
	tree.BuildExpression(prefix);
	cout<<"Postfix Order:";
	tree.DisplayPostfix(tree.root);
	cout<<endl;
	tree.DeleteTree(tree.root);
	return 0;
}



