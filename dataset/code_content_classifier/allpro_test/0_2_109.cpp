#include <iostream>
#include <vector>
#include <string>

#define MOD 998244353

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> dominoes(n);
    for (int i = 0; i < n; i++) {
        cin >> dominoes[i];
    }

    long long count = 1;
    long long whiteCount = 0, blackCount = 0;

    for (int i = 0; i < n; i++) {
        if (dominoes[i][0] == '?' && dominoes[i][1] == '?') {
            count = (count * 2) % MOD; // two possibilities
        } else if (dominoes[i][0] == '?' && dominoes[i][1] != '?') {
            if (dominoes[i][1] == 'W') {
                whiteCount++;
            } else {
                blackCount++;
            }
        } else if (dominoes[i][0] != '?' && dominoes[i][1] == '?') {
            if (dominoes[i][0] == 'W') {
                whiteCount++;
            } else {
                blackCount++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dominoes[i][0] != '?' && dominoes[i][1] != '?') {
            if (dominoes[i][0] == dominoes[i][1]) {
                cout << 0 << endl;
                return 0;
            }
        }
    }

    long long additional = 1;
    for (int i = 0; i < whiteCount; i++) {
        additional = (additional * (blackCount + i + 1)) % MOD;
    }
    for (int i = 0; i < blackCount; i++) {
        additional = (additional * (whiteCount + i + 1)) % MOD;
    }

    count = (count * additional) % MOD;

    cout << count << endl;

    return 0;
}