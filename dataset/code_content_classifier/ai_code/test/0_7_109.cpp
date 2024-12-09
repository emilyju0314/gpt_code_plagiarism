#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MOD 998244353

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> dominoes(n);
    for(int i = 0; i < n; i++) {
        cin >> dominoes[i];
    }

    long long ans = 1;
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(dominoes[i][0] == '?' && dominoes[i][1] == '?') {
            ans = (ans * 2) % MOD;
            count++;
        } else if((dominoes[i][0] == 'W' || dominoes[i][1] == 'W') && (dominoes[i][0] == 'B' || dominoes[i][1] == 'B')) {
            count++;
        }
    }

    for(int i = 1; i <= count; i++) {
        ans = (ans * i) % MOD;
    }

    cout << ans << endl;

    return 0;
}