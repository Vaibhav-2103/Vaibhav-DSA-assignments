#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int tri[3*n - 2] = {1,2,3,4, 5,6,7, 8,9,10};

    cout << "Tri-diagonal Matrix:\n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i==j) cout << tri[i] << " ";
            else if (i == j-1) cout << tri[n+i] << " ";
            else if (i == j+1) cout << tri[2*n-1+j] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}
