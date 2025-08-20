#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int upper[n*(n+1)/2] = {1,2,3,4, 5,6,7, 8,9, 10};

    cout << "Upper Triangular Matrix:\n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (j >= i) cout << upper[j*(j+1)/2 + i] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}
