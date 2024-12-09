#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n), q(n), perm(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    for (int i = 0; i < n; i++) {
        perm[p[i]] = i;
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = perm[q[i]];
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}