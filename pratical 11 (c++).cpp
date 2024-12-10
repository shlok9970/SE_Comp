#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if the given expression is well-parenthesized
bool isWellParenthesized(const string& expression) {
    stack<char> s;

    // Iterate through each character in the expression
    for (char ch : expression) {
        // If the character is an opening bracket, push it onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // If the character is a closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            // Check if the stack is empty (unmatched closing bracket)
            if (s.empty()) {
                return false;
            }
            // Check if the top of the stack matches the closing bracket
            char top = s.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                s.pop(); // Match found, pop the opening bracket
            } else {
                return false; // Mismatched brackets
            }
        }
    }

    // If the stack is empty, all brackets were matched
    return s.empty();
}

int main() {
    string expression;

    cout << "Enter an expression: ";
    getline(cin, expression);

    // Check if the expression is well-parenthesized
    if (isWellParenthesized(expression)) {
        cout << "The expression is well-parenthesized." << endl;
    } else {
        cout << "The expression is not well-parenthesized." << endl;
    }

    return 0;
}