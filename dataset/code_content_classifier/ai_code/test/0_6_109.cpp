#include <iostream>
#include <vector>
#define MOD 998244353

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    vector<int> waysW(n+1, 0); // Number of ways to color left cell white for the i-th domino
    vector<int> waysB(n+1, 0); // Number of ways to color left cell black for the i-th domino

    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s[0] == '?' && s[1] == '?') {
            waysW[i] = waysB[i] = (waysW[i] + waysB[i]) % MOD;
            waysW[i+1] = (waysW[i] * 2) % MOD;
            waysB[i+1] = (waysB[i] * 2) % MOD;
        } else if (s[0] == '?' || s[1] == '?') {
            waysW[i] = waysB[i] = (waysW[i] + waysB[i]) % MOD;
            if (s[0] == 'W' || s[1] == 'W') {
                waysW[i+1] = (waysW[i] + waysB[i]) % MOD;
                waysB[i+1] = (waysB[i] * 2) % MOD;
            } else {
                waysW[i+1] = (waysW[i] * 2) % MOD;
                waysB[i+1] = (waysB[i] + waysW[i]) % MOD;
            }
        } else {
            waysW[i+1] = waysW[i];
            waysB[i+1] = waysB[i];
            if (s[0] == 'B' && s[1] == 'B') {
                cout << 0 << endl;
                return 0;
            }
        }
    }

    cout << (waysW[n] + waysB[n]) % MOD << endl;

    return 0;
}