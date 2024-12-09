#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findPermutation(int n, vector<int>& next) {
    vector<int> p(n);
    vector<int> ans(n, -1);
    vector<int> available(n + 1, true);

    int prev = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (next[i] == -1) {
            while (!available[j]) {
                j++;
            }
            p[i] = j + 1;
            available[j] = false;
        } else {
            if (next[i] < prev || (next[i] > n && prev != n + 1)) {
                return vector<int>(n, -1);
            }
            if (next[i] == n + 1) {
                p[i] = n;
                prev = n + 1;
            } else {
                p[i] = next[i];
                prev = next[i];
            }
        }
    }

    return p;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> next(n);
        for (int i = 0; i < n; i++) {
            cin >> next[i];
        }

        vector<int> result = findPermutation(n, next);

        if (result[0] == -1) {
            cout << -1 << endl;
        } else {
            for (int i = 0; i < n; i++) {
                cout << result[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}