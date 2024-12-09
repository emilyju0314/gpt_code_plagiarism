#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 998244353

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> cnt(n+2, -1);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long prev = 0, ans = 1;

        for(auto ele : a) {
            int mex = 0;
            if(cnt[ele] != -1) {
                mex = prev;
                prev = (prev - cnt[ele] + MOD) % MOD;
            } else {
                mex = prev + 1;
                prev = (prev + ans) % MOD;
            }
            cnt[ele] = mex;
            ans = (ans + mex) % MOD;
        }

        cout << ans << endl;
    }

    return 0;
}