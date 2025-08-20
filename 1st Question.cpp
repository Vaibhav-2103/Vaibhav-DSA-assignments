#include <iostream>
using namespace std;

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;  // found at index i
    }
    return -1; // not found
}

// Binary Search (array must be sorted)
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {11, 22, 25, 34, 64, 90}; // sorted array
    int n = 6, key;

    cout << "Enter element to search: ";
    cin >> key;

    // Linear Search
    int index1 = linearSearch(arr, n, key);
    if (index1 != -1)
        cout << "Found by Linear Search at index " << index1 << endl;
    else
        cout << "Not found by Linear Search\n";

    // Binary Search
    int index2 = binarySearch(arr, n, key);
    if (index2 != -1)
        cout << "Found by Binary Search at index " << index2 << endl;
    else
        cout << "Not found by Binary Search\n";

    return 0;
}
