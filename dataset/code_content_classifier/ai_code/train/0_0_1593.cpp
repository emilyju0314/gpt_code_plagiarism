#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int total_ones = count(a.begin(), a.end(), 1);
    int total_neg_ones = count(a.begin(), a.end(), -1);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;

        int length = r - l + 1;
        if (length % 2 != 0) {
            cout << "1" << endl;
        } else if (total_ones >= length / 2 && total_neg_ones >= length / 2) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }

    return 0;
}