#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int ans = 0;
    vector<int> ones;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ones.push_back(i);
        }
    }

    for (int i = 0; i < ones.size(); i++) {
        for (int j = i+1; j <= ones.size(); j++) {
            int cnt = 0;
            for (int x = i; x < j; x++) {
                if (s[ones[x]] == '1') {
                    cnt++;
                }
            }

            if (cnt == k) {
                long long ways = 1;
                for (int x = i; x < j; x++) {
                    ways *= 2;
                    ways %= MOD;
                }
                ans += ways;
                ans %= MOD;
            }
        }
    }

    cout << (ans + 1) % MOD << endl;

    return 0;
}