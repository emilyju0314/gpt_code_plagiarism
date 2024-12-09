#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> dominoes(n);
    for (int i = 0; i < n; i++) {
        cin >> dominoes[i];
    }

    long long ans = 1;
    long long countW = 0, countB = 0;
    for (int i = 0; i < n; i++) {
        if (dominoes[i][0] == '?' && dominoes[i][1] == '?') {
            ans *= 2;
            countW = (countW * 3 + countB) % MOD;
            countB = (countB * 3 + countW) % MOD;
        } else if (dominoes[i][0] == '?' && dominoes[i][1] != '?') {
            if (dominoes[i][1] == 'W') {
                countW = (countW + countB) % MOD;
            } else {
                countB = (countB + countW) % MOD;
            }
        } else if (dominoes[i][0] != '?' && dominoes[i][1] == '?') {
            if (dominoes[i][0] == 'W') {
                countW = (countW + countB) % MOD;
            } else {
                countB = (countB + countW) % MOD;
            }
        } else {
            if (dominoes[i][0] != dominoes[i][1]) {
                ans = (ans * 2) % MOD;
            }
        }
    }

    cout << (ans * (countW + countB) % MOD) << endl;

    return 0;
}