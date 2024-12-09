#include <iostream>
#include <vector>

using namespace std;

void solve(int n, int a, int b) {
    if (a == 0 && b == 0) {
        if (n == 1) {
            cout << 1 << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }

    if (a == 0 || b == 0 || a + b >= n || a*2 > n || b*2 > n) {
        cout << -1 << endl;
        return;
    }

    vector<int> permutation;
    for (int i = 1; i <= a + 1; i++) {
        permutation.push_back(i*2);
    }

    for (int i = 1; i <= a + 1; i++) {
        if (i == a + 1 && b > 0) {
            permutation.push_back(1);
            b--;
        } else {
            permutation.push_back(i*2 - 1);
        }
    }

    for (int i = a + 2; i <= n - b; i++) {
        permutation.push_back(2*i - n - 1);
    }

    if (permutation.size() != n) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << permutation[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        solve(n, a, b);
    }

    return 0;
}