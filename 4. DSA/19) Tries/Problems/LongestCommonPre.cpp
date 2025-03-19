#include <iostream>
#include <vector>
#include <string>
using namespace std;
//link: https://leetcode.com/problems/longest-common-prefix/description/

class TrieNode {
public:
    char ch;
    TrieNode* children[26];
    bool isTerminal;
    int childCnt;

    TrieNode(char d) {
        this->ch = d;
        this->isTerminal = false;
        for (int i = 0; i < 26; i++) {
            this->children[i] = NULL;
        }
        this->childCnt = 0;
    }
};

class Solution {
public:
    void insertWord(TrieNode* root, string word) {
        cout << "Inserting word: " << word << ", Current node char: " << root->ch << endl;

        // Base case
        if (word.length() == 0) {
            root->isTerminal = true;
            cout << "Reached end of word, set isTerminal = true for char: " << root->ch << endl;
            return;
        }

        // Process current character
        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child = NULL;

        if (root->children[index] != NULL) {
            child = root->children[index];
            cout << "Character '" << ch << "' already exists, moving to child node" << endl;
        } else {
            child = new TrieNode(ch);
            root->childCnt++;
            root->children[index] = child;
            cout << "Created new node for '" << ch << "', childCnt incremented to: " << root->childCnt << endl;
        }

        insertWord(child, word.substr(1));
    }

    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');
        cout << "Initialized root node with char: " << root->ch << endl;

        // Insert all strings into the Trie
        for (int i = 0; i < strs.size(); i++) {
            cout << "\nInserting string " << i + 1 << ": " << strs[i] << endl;
            insertWord(root, strs[i]);
        }

        // Check if root is terminal (empty string case)
        if (root->isTerminal) {
            cout << "Root is terminal, returning empty string" << endl;
            return "";
        }

        string st = strs[0];
        string ans = "";
        cout << "\nFinding longest common prefix using first string: " << st << endl;

        // Traverse Trie to find common prefix
        for (int i = 0; i < st.length(); i++) {
            char ch = st[i];
            int index = ch - 'a';
            cout << "Checking char '" << ch << "' at position " << i << ", childCnt = " << root->childCnt << endl;

            if (root->childCnt == 1 && root->children[index] != NULL) {
                ans.push_back(ch);
                cout << "Added '" << ch << "' to prefix, current prefix: " << ans << endl;
                root = root->children[index];
                cout << "Moved to child node with char: " << root->ch << endl;

                if (root->isTerminal) {
                    cout << "Node is terminal, stopping here" << endl;
                    break;
                }
            } else {
                cout << "childCnt != 1 or child not found, stopping prefix search" << endl;
                break;
            }
        }

        cout << "Final longest common prefix: " << ans << endl;
        return ans;
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    // Test case
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Input strings:" << endl;
    for (const string& s : strs) {
        cout << s << endl;
    }

    string result = solution.longestCommonPrefix(strs);

    cout << "\nResult: " << result << endl;

    return 0;
}