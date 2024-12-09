#include <iostream>
#include <vector>

#define MOD (int)(1e9 + 7)

using namespace std;

vector<int> fib;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    if (fib[n] != -1) {
        return fib[n];
    }
    return fib[n] = (fibonacci(n - 1) + fibonacci(n - 2)) % MOD;
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

    fib.assign(N + 1, -1);
    fib[0] = 0;
    fib[1] = 1;

    while (Q--) {
        int type, k, l, r, x;
        cin >> type >> k >> l >> r;
        l--, r--;

        if (type == 1) {
            cin >> x;
            for (int i = l; i <= r; i++) {
                A1[i] = min(A1[i], x);
            }
        } else if (type == 2) {
            cin >> x;
            for (int i = l; i <= r; i++) {
                A1[i] = max(A1[i], x);
            }
        } else if (type == 3) {
            cin >> x;
            for (int i = l; i <= r; i++) {
                A1[i] = (A1[i] + x) % MOD;
            }
        } else {
            int result = 0;
            for (int i = l; i <= r; i++) {
                result = (result + fibonacci(A1[i] + A2[i])) % MOD;
            }
            cout << result << endl;
        }
    }

    return 0;
}