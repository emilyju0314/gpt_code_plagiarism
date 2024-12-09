#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 5e4;

int F[MAXN + 2];

int fibonacci(int k) {
    return F[k];
}

int main() {
    F[0] = 0;
    F[1] = 1;
    for(int i = 2; i <= MAXN + 1; i++) {
        F[i] = (F[i - 1] + F[i - 2]) % MOD;
    }

    int N, Q;
    cin >> N >> Q;

    vector<int> A1(N), A2(N);
    for(int i = 0; i < N; i++) {
        cin >> A1[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> A2[i];
    }

    while(Q--) {
        int type;
        cin >> type;

        if(type == 4) {
            int l, r;
            cin >> l >> r;
            int sum = 0;
            for(int i = l - 1; i < r; i++) {
                sum += fibonacci(A1[i] + A2[i]);
                sum %= MOD;
            }
            cout << sum << endl;
        } else {
            int k, l, r, x;
            cin >> k >> l >> r >> x;
            if(k == 1) {
                for(int i = l - 1; i < r; i++) {
                    A1[i] = min(A1[i], x);
                }
            } else if(k == 2) {
                for(int i = l - 1; i < r; i++) {
                    A1[i] = max(A1[i], x);
                }
            } else {
                for(int i = l - 1; i < r; i++) {
                    A1[i] = (A1[i] + x) % MOD;
                }
            }
        }
    }

    return 0;
}