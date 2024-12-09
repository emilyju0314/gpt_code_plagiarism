#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<string> dominoes(n);
    for (int i = 0; i < n; i++) {
        cin >> dominoes[i];
    }

    long long ans = 1;
    int unknownCount = 0;

    for (int i = 0; i < n; i++) {
        if (dominoes[i][0] == 'B' && dominoes[i][1] == 'W') {
            ans = (ans * 2) % MOD;
        } else if (dominoes[i][0] == 'W' && dominoes[i][1] == 'B') {
            ans = (ans * 1) % MOD;
        } else if (dominoes[i][0] == '?' && dominoes[i][1] == '?') {
            unknownCount++;
        }
    }

    ans = (ans * pow(2, unknownCount)) % MOD;

    cout << ans << endl;

    return 0;
}