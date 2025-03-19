#include <iostream>
#include <string>
using namespace std;
//Link:https://classroom.codingninjas.com/app/classroom/me/18751/content/372778/offering/5270094/problem/1392
// Array representing the keypad mappings
string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// Recursive function to generate all possible combinations
void print(int num, string output) {
    if (num == 0) {
        if (output != " ") { // Avoid printing for the initial empty output
            cout << output << endl;
        }
        return;
    }
    string temp = keypad[num % 10];
    for (int i = 0; i < temp.size(); i++) {
        print(num / 10, temp[i] + output);
    }
}

// Function to handle the initial call for print combinations
void printKeypad(int num) {
    // Handle case when num is 0
    if (num == 0) {
        cout << " " << endl; // Edge case for input 0
        return;
    }
    string output = "";
    print(num, output);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    // Call the printKeypad function to print all combinations
    cout << "Possible combinations for " << num << ":" << endl;
    printKeypad(num);

    return 0;
}
//debug print 
#include <iostream>
#include <string>
using namespace std;

// Array representing the keypad mappings
string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// Recursive function to generate all possible combinations
void print1(int num, string output, int depth = 0) { // depth is optional
    // Indentation for debug output
    string indent(depth * 2, ' '); 
    cout << indent << "DEBUG: print(num=" << num << ", output=\"" << output << "\")" << endl;

    if (num == 0) {
        cout << indent << "DEBUG: Base case reached" << endl;
        if (output != " ") { // Avoid printing initial empty output
            cout << indent << "DEBUG: Printing \"" << output << "\"" << endl;
            cout << output << endl; // Actual output
        } else {
            cout << indent << "DEBUG: Skipping empty output" << endl;
        }
        return;
    }

    string temp = keypad[num % 10];
    cout << indent << "DEBUG: temp = \"" << temp << "\" (keypad[" << (num % 10) << "])" << endl;
    cout << indent << "DEBUG: num / 10 = " << (num / 10) << endl;

    for (int i = 0; i < temp.size(); i++) {
        cout << indent << "DEBUG: Calling print with '" << temp[i] << "' + \"" << output << "\"" << endl;
        print1(num / 10, temp[i] + output, depth + 1); // Pass depth + 1
    }
}

// Function to handle the initial call for print combinations
void printKeypad1(int num) {
    cout << "DEBUG: printKeypad(" << num << ")" << endl;
    if (num == 0) {
        cout << "DEBUG: Edge case num = 0" << endl;
        cout << " " << endl; // Edge case output
        return;
    }
    string output = "";
    cout << "DEBUG: Starting recursion with output = \"" << output << "\"" << endl;
    print1(num, output); // Initial call uses default depth = 0
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Possible combinations for " << num << ":" << endl;
    printKeypad1(num);

    return 0;
}