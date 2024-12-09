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
            cnt[min(a[i], n)]++;
        }

        while (cnt[mex] > 0) {
            mex++;
        }

        vector<int> ans(n + 1, -1);
        for (int i = 0; i < n; i++) {
            cnt[a[i]]--;
            if (cnt[a[i]] == 0 && a[i] < mex) {
                mex = a[i];
            }
            ans[mex] = i + 1;
        }

        for (int i = 0; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}