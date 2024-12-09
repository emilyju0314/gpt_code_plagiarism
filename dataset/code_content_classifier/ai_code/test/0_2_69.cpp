#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

vector<int> fib;

void generateFibonacci(int n) {
    fib.resize(n + 1);
    fib[0] = 0, fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A1(N), A2(N);
    for (int i = 0; i < N; i++) {
        cin >> A1[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> A2[i];
    }

    generateFibonacci(N);

    for (int q = 0; q < Q; q++) {
        int type, k, l, r, x;
        cin >> type;
        if (type == 4) {
            cin >> l >> r;
            int sum = 0;
            for (int i = l - 1; i < r; i++) {
                sum = (sum + fib[A1[i] + A2[i]]) % MOD;
            }
            cout << sum << endl;
        } else {
            cin >> k >> l >> r >> x;
            if (type == 1) {
                for (int i = l - 1; i < r; i++) {
                    A1[i] = min(A1[i], x);
                }
            } else if (type == 2) {
                for (int i = l - 1; i < r; i++) {
                    A1[i] = max(A1[i], x);
                }
            } else if (type == 3) {
                for (int i = l - 1; i < r; i++) {
                    A1[i] = (A1[i] + x) % MOD;
                }
            }
        }
    }

    return 0;
}