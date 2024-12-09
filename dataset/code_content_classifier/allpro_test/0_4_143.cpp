#include <iostream>
#include <vector>

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

        int mex = 0;
        vector<int> cnt(n + 2, 0);
        for (int i = 0; i < n; i++) {
            cnt[a[i]]++;
        }

        while (cnt[mex] > 0) {
            mex++;
        }

        vector<int> ans(n + 1, -1);
        for (int i = 0; i <= n; i++) {
            if (mex <= i) {
                ans[i] = n - (cnt[mex] == 0);
            } else {
                ans[i] = n;
            }

            if (a[n - 1] < i) {
                ans[i]++;
            }

            if (mex == i) {
                mex++;
                while (cnt[mex] > 0) {
                    mex++;
                }
            }
        }

        for (int i = 0; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}