#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long ans = 0;

        for(int i = 0; i < n; i++) {
            long long cnt = 0;
            int curr = a[i];

            for(int j = i; j < n; j++) {
                curr = min(curr, a[j]); // get the minimum element in the subarray
                cnt += curr;
                ans = (ans + cnt) % MOD;
            }
        }

        cout << ans << endl;
    }

    return 0;
}