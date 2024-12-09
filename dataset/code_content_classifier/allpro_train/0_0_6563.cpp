#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;

    if (abs(N - M) > 1) {
        cout << 0 << endl;
        return 0;
    }

    long long ans = 1;
    for (int i = 1; i <= N; i++) {
        ans = (ans * i) % MOD;
    }
    for (int i = 1; i <= M; i++) {
        ans = (ans * i) % MOD;
    }
    
    if (N == M) {
        ans = (ans * 2) % MOD;
    }

    cout << ans << endl;
    
    return 0;
}