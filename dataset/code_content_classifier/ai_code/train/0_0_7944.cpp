#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main() {
    int N, X, D;
    cin >> N >> X >> D;

    if (D == 0) {
        if (X == 0) {
            cout << "1" << endl;
        } else {
            cout << N+1 << endl;
        }
        return 0;
    }

    X = abs(X);
    int sign = (X / D) % 2 == 0 ? 1 : -1;
    X %= D;

    long long mi = 0, ma = 0;
    long long T, S;

    set<pair<long long, long long>> used_pairs;
    for (int i = 0; i <= N; ++i) {
        T = 1ll * i * (i - 1) / 2;
        S = 1ll * N * (N - 1) / 2 + 1ll * i * (N - i);

        long long rest = S - T;
        long long p = i * D;
        long long q = rest % D + (rest / D + 1) * sign;

        if (q > 0) {
            mi = mi + p * q / 2;
        } else {
            ma = ma + p * q / 2;
        }

        if (used_pairs.find({p, q}) == used_pairs.end()) {
            mi += i;
            ma += i;
            used_pairs.insert({p, q});
        }
    }

    cout << ma - mi + 1 << endl;

    return 0;
}