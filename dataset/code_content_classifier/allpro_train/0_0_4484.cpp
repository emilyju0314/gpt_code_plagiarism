#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    int N, M;
    cin >> N >> M;
    string A, B, C, D;
    cin >> A >> B >> C >> D;

    vector<int> pow2(N + M + 3);
    pow2[0] = 1;
    for (int i = 1; i < N + M + 3; i++) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }

    int ans = 1;
    int colA = 0, colB = 0, rowC = 0, rowD = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == '1' && B[i] == '1') {
            ans = (ans * 2) % MOD;
        } else if (A[i] == '1') {
            colA++;
        } else if (B[i] == '1') {
            colB++;
        }
    }

    for (int i = 0; i < M; i++) {
        if (C[i] == '1' && D[i] == '1') {
            ans = (ans * 2) % MOD;
        } else if (C[i] == '1') {
            rowC++;
        } else if (D[i] == '1') {
            rowD++;
        }
    }

    ans = (ans * pow2[colA + colB + rowC + rowD]) % MOD;
    cout << ans << endl;

    return 0;
}