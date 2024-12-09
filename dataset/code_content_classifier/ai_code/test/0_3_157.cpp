#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MOD 998244353

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int count_ones = 0;
    vector<int> cnt(n+1, 0);
    for(int i = 0; i < n; i++) {
        count_ones += (s[i] == '1');
        cnt[i+1] = count_ones;
    }

    long long ans = 0;

    if(k == 0) {
        ans = 1;
    } else if(k == 1) {
        ans = count_ones;
    } else {
        // Every string formed from performing the operation will have the same number of '1's as the original string
        for(int i = 1; i <= k; i++) {
            long long c = 1;
            for(int j = 1; j <= k - i; j++) {
                c = c * (i + j) % MOD;
                c = c * ((n - k + 1) - j + 1) % MOD;
            }
            ans = (ans + c) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}