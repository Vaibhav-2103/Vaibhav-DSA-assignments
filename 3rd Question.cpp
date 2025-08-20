#include <iostream>
using namespace std;

// Linear search approach - O(n)
int findMissingLinear(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return -1;  // Return -1 if no missing number found
}

// Binary search approach - O(log n)
int findMissingBinary(int arr[], int size) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == mid + 1) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // If we've checked all elements and left == size, no missing number
    return (left < size) ? left + 1 : -1;
}

int main() {
    int arr1[] = {1, 2, 3, 5, 6, 7}; // Missing 4
    int size1 = sizeof(arr1)/sizeof(arr1[0]);

    cout << "missing number :" << endl;
    cout << "Linear search result: " << findMissingLinear(arr1, size1) << endl;
    cout << "Binary search result: " << findMissingBinary(arr1, size1) << endl;
    return 0;
}
