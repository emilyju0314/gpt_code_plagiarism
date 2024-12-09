#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        string s, t;
        cin >> s >> t;

        long long ans = 1;

        for (int i = 0; i < n; i++) {
            if (s[i] == '?' && t[i] == '?') {
                ans = (ans * 2) % MOD;
            } else if (s[i] != '?' && t[i] != '?' && s[i] != t[i]) {
                ans = 0;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}