#include <iostream>
using namespace std;

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    int n = arr.size();
    int inv = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i] > arr[j]) inv++;
        }
    }
    cout << "Inversions = " << inv << endl;
    return 0;
}
