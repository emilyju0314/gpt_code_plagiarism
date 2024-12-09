#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

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
            int left = a[i], right = a[i], cnt_left = 1, cnt_right = 1;

            for(int j = i-1; j >= 0; j--) {
                if(a[j] < left) {
                    ans = (ans + min(left, a[i]) % MOD) % MOD;
                    left -= a[j];
                    cnt_left++;
                } else {
                    break;
                }
            }

            for(int j = i+1; j < n; j++) {
                if(a[j] < right) {
                    ans = (ans + min(right, a[i]) % MOD) % MOD;
                    right -= a[j];
                    cnt_right++;
                } else {
                    break;
                }
            }

            ans = (ans + min(left, a[i]) % MOD) % MOD;
            ans = (ans + min(right, a[i]) % MOD) % MOD;
            ans = (ans + (cnt_left * cnt_right) % MOD) % MOD;
        }

        cout << ans << endl;
    }

    return 0;
}