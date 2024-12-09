#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long powMod(long long base, long long exp) {
    long long result = 1;
    base = base % MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        exp = exp >> 1;
        base = (base * base) % MOD;
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int uncolored = 0, white = 0, black = 0;
    for (char c : s) {
        if (c == 'w') white++;
        else if (c == 'b') black++;
        else uncolored++;
    }

    long long ans = 0;
    if (black % 2 == 0 && white % 2 == 0) {
        ans = (1LL * uncolored * powMod(2, uncolored - 1)) % MOD;
    }

    cout << ans << endl;

    while (m--) {
        int pos;
        char color;
        cin >> pos >> color;

        if (s[pos - 1] == '?') uncolored--;
        else if (s[pos - 1] == 'w') white--;
        else black--;

        if (color == '?') uncolored++;
        else if (color == 'w') white++;
        else black++;

        long long ans = 0;
        if (black % 2 == 0 && white % 2 == 0) {
            ans = (1LL * uncolored * powMod(2, uncolored - 1)) % MOD;
        }

        cout << ans << endl;

        s[pos - 1] = color;
    }

    return 0;
}