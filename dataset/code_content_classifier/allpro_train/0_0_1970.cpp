#include <iostream>
#define MOD 998244353
using namespace std;

long long power(long long a, long long b) {
    long long res = 1;
    while(b > 0) {
        if(b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    int N, M;
    cin >> N >> M;

    long long ans = 1;
    for(int i = 1; i <= N; i++) {
        ans = (ans * (M - i + 1)) % MOD;
    }

    for(int i = 1; i <= M; i++) {
        ans = (ans * (N - i + 1)) % MOD;
    }

    ans = (ans * power(2, N * M - N - M)) % MOD;
    cout << ans << endl;

    return 0;
}