#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int sym[n*(n+1)/2] = {1,2,3,4, 5,6,7, 8,9, 10};

    cout << "Symmetric Matrix:\n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i >= j) cout << sym[i*(i+1)/2 + j] << " ";
            else cout << sym[j*(j+1)/2 + i] << " ";
        }
        cout << endl;
    }
    return 0;
}
