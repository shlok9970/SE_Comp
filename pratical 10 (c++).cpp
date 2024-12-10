#include <iostream>
#include <stack>
#include <cctype>
#include <string>

using namespace std;

// Function to clean the input string by removing punctuation, spaces, and converting to lowercase
string cleanString(const string& str) {
    string cleaned;
    for (char ch : str) {
        if (isalnum(ch)) { // Check if the character is alphanumeric
            cleaned += tolower(ch); // Convert to lowercase
        }
    }
    return cleaned;
}

// Function to print the original string followed by the reversed string using a stack
void printOriginalAndReversed(const string& str) {
    stack<char> charStack;
    
    // Push characters onto the stack
    for (char ch : str) {
        if (isalnum(ch)) { // Only consider alphanumeric characters
            charStack.push(tolower(ch)); // Convert to lowercase and push
        }
    }

    // Print original string
    cout << "Original string: " << str << endl;

    // Print reversed string
    cout << "Reversed string: ";
    while (!charStack.empty()) {
        cout << charStack.top();
        charStack.pop();
    }
    cout << endl;
}

// Function to check whether the given string is a palindrome
bool isPalindrome(const string& str) {
    string cleaned = cleanString(str);
    stack<char> charStack;

    // Push characters onto the stack
    for (char ch : cleaned) {
        charStack.push(ch);
    }

    // Check if the cleaned string is a palindrome
    for (char ch : cleaned) {
        if (charStack.top() != ch) {
            return false; // Not a palindrome
        }
        charStack.pop();
    }
    return true; // Is a palindrome
}

int main() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    // Print original and reversed string
    printOriginalAndReversed(input);

    // Check if the string is a palindrome
    if (isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}