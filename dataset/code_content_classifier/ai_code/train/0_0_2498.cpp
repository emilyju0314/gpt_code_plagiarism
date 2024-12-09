#include <iostream>
#include <cmath>

using namespace std;

long long fast_expo(long long a, long long b, long long m) {
    long long res = 1;
    a = a % m;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }
        b = b >> 1;
        a = (a * a) % m;
    }
    return res;
}

int main() {
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        long long A, M;
        cin >> A >> M;

        if (A == 0) {
            cout << "1" << endl;
            continue;
        }

        long long ans = -1;
        for (long long K = 1; K <= 2 * 1000000000000000000; K++) {
            if (fast_expo(A, K, M) == K) {
                ans = K;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}