#include <iostream>
#include <vector>
using namespace std;

// Mapping of digits to corresponding letters
vector<string> mapping = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

// Recursive function to generate letter combinations
vector<string> generateCombinations(string digits, int index) {
    // Base Case: If index reaches the end, return a list with an empty string
    if (index == digits.length()) {
        return {""}; // Base case for combining
    }

    // Get the letters for the current digit
    string letters = mapping[digits[index] - '0'];

    // Recursive call to get combinations for the remaining digits
    vector<string> smallOutput = generateCombinations(digits, index + 1);

    // Store final combinations
    vector<string> result;

    // Combine current digit's letters with previous results
    for (char letter : letters) {
        for (string s : smallOutput) {
            result.push_back(letter + s);
        }
    }

    return result;
}

// Wrapper function
vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    return generateCombinations(digits, 0);
}

int main() {
    string digits = "23";
    vector<string> result = letterCombinations(digits);

    // Print the result
    for (string s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}