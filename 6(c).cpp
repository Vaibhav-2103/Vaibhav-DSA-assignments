#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

int main() {
    vector<Element> A = {{0,0,5}, {0,2,8}, {2,1,6}};
    vector<Element> B = {{0,1,7}, {2,1,6}};
    vector<Element> M;
    for (auto &a : A) {
        for (auto &b : B) {
            if (a.col == b.row) {
                M.push_back({a.row, b.col, a.val * b.val});
            }
        }
    }
    for (auto &e : M) cout << "("<<e.row<<","<<e.col<<","<<e.val<<") ";
    cout << endl;
    return 0;
}
