#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;
    ll A = 0, B = 0, C = 0, N = 1;
    for (char c : S) {
        if (c == 'A') A = (A + N) % MOD;
        if (c == 'B') B = (B + A) % MOD;
        if (c == 'C') C = (C + B) % MOD;
        if (c == '?') {
            C = (3 * C + B) % MOD;
            B = (3 * B + A) % MOD;
            A = (3 * A + N) % MOD;
            N = 3 * N % MOD;
        }
    }
    cout << C << endl;
}