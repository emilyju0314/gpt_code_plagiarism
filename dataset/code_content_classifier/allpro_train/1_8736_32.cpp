#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int INF = 1e9;

int main() {
    int n;
    while(cin >> n, n) {
        string s; cin >> s;
        vector<int> dp(1 << 10);
        vector<bool> used(1 << 10);
        int state = 0;
        for(int i = 0; i + 1 < n; ++i) {
            if(s[i] == 'u') {
                state = 0;
            } else {
                state |= (1 << (s[i] - '0'));
            }
            if(s[i + 1] != 'u') {
                int d = s[i + 1] - '0';
                dp[state] |= (1 << d);
                used[state] = true;
            }
        }

        for(int S = 0; S < (1 << 10); ++S) {
            for(int T = S + 1; T < (1 << 10); ++T) {
                if(used[S] && used[T] && (S & T) == 0) {
                    dp[S | T] |= dp[S] | dp[T];
                    used[S | T] = true;
                }
            }
        }

        bool ng = false;
        for(int S = 1; S < (1 << 10); ++S) {
            if(used[S]) {
                ng |= (dp[S] & S) == dp[S];
            }
        }
        if(ng) {
            cout << "UNSAFE" << endl;
        } else {
            cout << "SAFE" << endl;
        }
    }
}
