#include <bits/stdc++.h>
using namespace std;

bool solve(int n, int k) {
    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
    }

    if (k > n * (n + 1) / 2) {
        return false;
    }

    vector<int> beauty(n, 1);
    k -= n;
    for (int i = n - 1; i >= 1; i--) {
        if (k >= i) {
            k -= i;
            beauty[i - 1] = i + 1;
        } else {
            beauty[i - 1] += k;
            break;
        }
    }

    reverse(perm.begin(), perm.end());
    for (int i = 0; i < n; i++) {
        if (beauty[i] % 2 == 1) {
            reverse(perm.begin() + i, perm.begin() + i + beauty[i]);
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << perm[i] << " ";
    }
    cout << endl;

    return true;
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n, k;
        cin >> n >> k;

        if (!solve(n, k)) {
            cout << "NO" << endl;
        }
    }

    return 0;
}