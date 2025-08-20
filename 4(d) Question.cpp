#include <iostream>
#include <string>
using namespace std;

void sortStrings(string arr[], int n) {
    // Simple Bubble Sort implementation
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap the strings
                string temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    string fruits[] = {"banana", "apple", "orange", "grape", "pear"};
    int n = sizeof(fruits)/sizeof(fruits[0]);

    cout << "Original array:\n";
    for (int i = 0; i < n; i++) {
        cout << fruits[i] << " ";
    }

    sortStrings(fruits, n);

    cout << "\n\nSorted array:\n";
    for (int i = 0; i < n; i++) {
        cout << fruits[i] << " ";
    }

    return 0;
}
