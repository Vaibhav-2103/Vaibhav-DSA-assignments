#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 5};
    sort(arr.begin(), arr.end());
    int cnt = 1;
    for (int i=1; i<arr.size(); i++) {
        if (arr[i] != arr[i-1]) cnt++;
    }
    cout << "Distinct elements = " << cnt << endl;
    return 0;
}
