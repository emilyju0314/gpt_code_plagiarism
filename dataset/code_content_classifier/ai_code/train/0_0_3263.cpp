#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int q = 0; q < Q; q++) {
        int type;
        cin >> type;

        if (type == 0) {
            int l, r, b, c;
            cin >> l >> r >> b >> c;
            l--;

            for (int i = l; i < r; i++) {
                a[i] = (b * a[i] + c) % MOD;
            }
        } else if (type == 1) {
            int l, r;
            cin >> l >> r;
            l--;

            long long sum = 0;
            for (int i = l; i < r; i++) {
                sum += a[i];
                sum %= MOD;
            }

            cout << sum << endl;
        }
    }

    return 0;
}