#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> mex(n+2, 0);

        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, a[i]);
            mex[a[i]] = 1;
        }

        int cnt = count(a.begin(), a.end(), mx);
        mex[mx] = (cnt == 1) ? 1 : 0;

        int prefixSum = 0;
        for (int i = 0; i <= n; i++) {
            prefixSum += mex[i];
            mex[i] = prefixSum;
        }

        for (int i = 0; i <= n; i++) {
            if (mex[i] == 0) {
                cout << "-1 ";
            } else {
                cout << n - mex[i] + 1 << " ";
            }
        }

        cout << endl;
    }

    return 0;
}