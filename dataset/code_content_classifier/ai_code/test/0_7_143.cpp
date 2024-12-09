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
        vector<int> freq(n + 2, 0);

        int mex = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == mex) {
                while (freq[mex] > 0) {
                    mex++;
                }
            }
            freq[a[i]]++;
        }

        freq[mex] = 1;
        int idx = 0;
        vector<int> ans(n + 2);

        while (freq[idx] > 0) {
            freq[idx] = 0;
            ans[idx] = 1;
            idx++;
        }

        while (idx <= n) {
            ans[idx] = -1;
            idx++;
        }

        for (int i = 0; i <= n; i++) {
            cout << ans[i] << " ";
        }

        cout << endl;
    }

    return 0;
}