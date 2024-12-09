#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<string> dominoes(n);
    for(int i = 0; i < n; i++) {
        cin >> dominoes[i];
    }

    long long ans = 1;
    int blackCount = 0, whiteCount = 0;
    for(int i = 0; i < n; i++) {
        if(dominoes[i][0] == 'B' && dominoes[i][1] == '?') {
            blackCount++;
        } else if(dominoes[i][0] == 'W' && dominoes[i][1] == '?') {
            whiteCount++;
        } else if(dominoes[i][0] == '?' && dominoes[i][1] == 'B') {
            blackCount++;
        } else if(dominoes[i][0] == '?' && dominoes[i][1] == 'W') {
            whiteCount++;
        } else if(dominoes[i][0] == '?' && dominoes[i][1] == '?') {
            ans = (ans * 2) % MOD;
        }
    }

    for(int i = 0; i < blackCount; i++) {
        ans = (ans * (whiteCount + i + 1)) % MOD;
    }

    cout << ans << endl;

    return 0;
}