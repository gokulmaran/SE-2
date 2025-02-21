#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Function to generate unique contiguous subarrays of sizes 2 to k
void generateCombinations(vector<int>& arr, int k) {
    int n = arr.size();
    set<vector<int>> uniqueCombinations;

    for (int size = 2; size <= k; size++) {
    for (int i = 0; i <= n - size; i++) {
        vector<int> subarray;
        
        // Manually push elements from index i to i+size-1
        for (int j = i; j < i + size; j++) {
            subarray.push_back(arr[j]);
        }

        // Ensure all elements in the subarray are unique (avoid duplicates like (2,2))
        set<int> uniqueElements(subarray.begin(), subarray.end());
        if (uniqueElements.size() == subarray.size()) {
            uniqueCombinations.insert(subarray);
        }
    }
    }

    // Print unique valid combinations
	int cnt=0;
    cout << "Unique Combinations of sizes 2 to " << k << ":\n";
    for (auto& comb : uniqueCombinations) {
        cout << "(";
        for (size_t i = 0; i < comb.size(); i++) {
            cout << comb[i];
            if (i < comb.size() - 1) cout << ", ";
        }
        cout << ") ";
		cnt++;
		cout<<endl;
    }
	cout<<cnt;
}

int main() {
    vector<int> arr = {1, 2, 2, 4, 5, 6};  // Input array
    int k = 3;  // Change k to 3 or 4 to get longer valid combinations

    generateCombinations(arr, k);
    return 0;
}
