#include <iostream>
#include <vector>
#include <cmath>

#define MOD 998244353

using namespace std;

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<long long> B(N);
    long long sum_B = 0;
    for (int i = 0; i < N; i++) {
        B[i] = N * A[i] - sum_B;
        sum_B += A[i];
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int q, i, d;
            cin >> q >> i >> d;

            long long old_val = B[i - 1];
            B[i - 1] = q - d * (N - 1);
            sum_B += B[i - 1] - old_val;
        }

        if (type == 2) {
            int q, L, R, d;
            cin >> q >> L >> R >> d;

            long long total_multiplier = power(d, K);
            long long delta_sum = (total_multiplier - 1) * power(d - 1, MOD - 2) % MOD;

            sum_B = (sum_B + delta_sum * (B[R - 1] - B[L - 1])) % MOD;
            B[L - 1] = (B[L - 1] + delta_sum * (q - R * d)) % MOD;
            B[R - 1] = (B[R - 1] + delta_sum * (q - L * d)) % MOD;
        }

        long long result = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                result = (result + B[i] * B[j]) % MOD;
            }
        }

        cout << result << endl;
    }

    return 0;
}