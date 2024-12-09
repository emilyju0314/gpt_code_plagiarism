#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 998244353;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> S(N, 1);

    for (int i = 0; i < Q; i++) {
        int L, R, D;
        cin >> L >> R >> D;

        for (int j = L - 1; j < R; j++) {
            S[j] = D;
        }

        long long ans = 0;
        long long exp = 1;
        for (int j = N - 1; j >= 0; j--) {
            ans = (ans + S[j] * exp) % MOD;
            exp = (exp * 10) % MOD;
        }

        cout << ans << endl;
    }

    return 0;
}