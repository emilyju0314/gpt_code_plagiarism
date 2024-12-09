#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    int N;
    long long x0;
    cin >> N >> x0;

    vector<long long> a(N), b(N), c(N), d(N), e(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
    }

    int steps = 0;
    int state = 1;
    while (state != N + 1) {
        if (steps > 1e6) {
            cout << -1 << endl;
            return 0;
        }

        if (x0 == a[state - 1]) {
            x0 += b[state - 1];
            state = c[state - 1];
        } else {
            x0 += d[state - 1];
            state = e[state - 1];
        }
        steps++;
    }

    cout << steps << endl;

    return 0;
}