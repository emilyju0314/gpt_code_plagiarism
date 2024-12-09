#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    if (a == 0 && b == 0) {
        if (n == 2) {
            cout << "1 2" << endl;
        } else {
            cout << "-1" << endl;
        }
        return;
    }

    if (a == 0 || b == 0 || a + b >= n || a + b < n - 1) {
        cout << "-1" << endl;
        return;
    }

    vector<int> permutation;
    for (int i = 1; i <= b + 1; i++) {
        permutation.push_back(i);
    }

    int last = b + 1;
    for (int i = 0; i < a; i++) {
        permutation.push_back(last + a - i);
    }

    for (int i = last + a - 1; i < n; i++) {
        if (permutation.back() == i) {
            cout << "-1" << endl;
            return;
        }
        permutation.push_back(i);
    }

    for (int i = 0; i < n; i++) {
        cout << permutation[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}