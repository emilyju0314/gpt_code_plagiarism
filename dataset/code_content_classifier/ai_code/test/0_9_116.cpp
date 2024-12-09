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
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int mex = 0;
        long long ans = 1;

        for(int i=0; i<n; i++) {
            if(a[i] >= mex) {
                ans = (ans * 2) % MOD;
            } else {
                ans = (ans + ans - power(2, mex - a[i] - 1)) % MOD;
            }

            mex = max(mex, a[i] + 1);
        }

        cout << (ans - 1 + MOD) % MOD << endl;
    }

    return 0;
}