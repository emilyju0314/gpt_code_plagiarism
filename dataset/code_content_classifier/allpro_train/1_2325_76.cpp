#include "bits/stdc++.h"
using namespace std;

void solve() {
    int N, x;
    cin >> N >> x;
    if (x == 1 || x == 2 * N - 1) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    int i = 0;
    for (int j = 0; j < 2 * N - 1; j++) {
        if (j == N - 2) {
            cout << x - 1 << endl << x << endl << x + 1 << endl;
            j += 2;
            continue;
        }
        if (i == x - 2) i += 3;
        cout << i + 1 << endl;
        i++;
    }
    return;
}

int main() {
    solve();
}