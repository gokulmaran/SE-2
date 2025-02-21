#include <iostream>
#include <vector>

using namespace std;

// Function to partition the array using the last element as pivot
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];    // Choose the last element as pivot
    int i = low - 1;          // Index of smaller element

    // Move all elements smaller than pivot to the left
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;              // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    
    // Place pivot in its correct position
    swap(arr[i + 1], arr[high]);
    return i + 1;            // Return pivot's position
}

// Recursive function to perform quick sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after the pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Helper function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function to test quick sort
int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}