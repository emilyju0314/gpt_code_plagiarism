#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

long long mod_pow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int N;
    long long M;
    cin >> N >> M;

    vector<long long> P(N+1);
    for (int i = 0; i <= N; i++) {
        cin >> P[i];
    }

    vector<long long> Q(N+1);
    for (int i = 0; i <= N; i++) {
        Q[i] = mod_pow(P[i], M);
    }

    vector<long long> R(N+1);
    for (int i = 0; i <= N; i++) {
        long long inv = mod_pow(Q[i], MOD - 2);
        for (int j = i; j <= N; j++) {
            R[j] = (R[j] + ((Q[i] * P[j-i]) % MOD) * inv) % MOD;
        }
    }

    for (int i = 0; i <= N; i++) {
        cout << R[i] << " ";
    }
    cout << endl;

    return 0;
}