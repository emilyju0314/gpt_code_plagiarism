#include <iostream>
#include <vector>
#include <unordered_map>
#define MOD 1000000007

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    unordered_map<long long, int> freq;
    int zeros = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == 0 && B[i] == 0) {
            zeros++;
            continue;
        }
        long long gcd = __gcd(A[i], B[i]);
        if (gcd != 0) {
            A[i] /= gcd;
            B[i] /= gcd;
            if (A[i] < 0) {
                A[i] = -A[i];
                B[i] = -B[i];
            }
        }
        if (A[i] < 0) {
            A[i] = -A[i];
            B[i] = -B[i];
        }
        if (A[i] == 0) {
            B[i] = 1;
        } else if (B[i] == 0) {
            A[i] = 1;
        } else {
            if (A[i] != 1) {
                long long gcd = __gcd(abs(A[i]), abs(B[i]));
                A[i] /= gcd;
                B[i] /= gcd;
            }
        }
        freq[A[i] * 1000000000LL + B[i]]++;
    }

    long long result = 1;
    for (auto& f : freq) {
        result = (result * ((1LL << f.second) + (1LL << freq[-(f.first % 1000000000) * 1000000000 - f.first / 1000000000]))) % MOD;
    }

    cout << (result + zeros - 1 + MOD) % MOD << endl;

    return 0;
}