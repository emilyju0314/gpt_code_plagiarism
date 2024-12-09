#include <iostream>
#include <cmath>
#include <vector>

#define MOD 1000000007

using namespace std;

vector<int> fib;

int F(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(fib[n] != -1) return fib[n];
    return fib[n] = (F(n-1) + F(n-2)) % MOD;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    fib.assign(N+1, -1);
    fib[0] = 0;
    fib[1] = 1;

    vector<int> A1(N);
    vector<int> A2(N);

    for(int i = 0; i < N; i++) {
        cin >> A1[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> A2[i];
    }

    for(int q = 0; q < Q; q++) {
        int type;
        cin >> type;

        if(type == 4) {
            int l, r;
            cin >> l >> r;
            int sum = 0;

            for(int i = l-1; i < r; i++) {
                sum = (sum + F(A1[i] + A2[i])) % MOD;
            }

            cout << sum << endl;
        } else {
            int k, l, r, x;
            cin >> k >> l >> r >> x;

            if (type == 1) {
                for(int i = l-1; i < r; i++) {
                    A1[i] = min(A1[i], x);
                }
            } else if (type == 2) {
                for(int i = l-1; i < r; i++) {
                    A1[i] = max(A1[i], x);
                }
            } else if (type == 3) {
                for(int i = l-1; i < r; i++) {
                    A1[i] = (A1[i] + x) % MOD;
                }
            }
        }
    }

    return 0;
}