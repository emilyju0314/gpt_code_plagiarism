#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        long long n, m, k;
        cin >> n >> m >> k;

        long long min_moves = max(abs(n), abs(m));
        long long diff = abs(n - m);
        long long extra_moves = max(0LL, (k - min_moves) % 2);

        if (k < min_moves || k < diff || k < n + m || extra_moves == 1) {
            cout << -1 << endl;
        } else {
            cout << k << endl;
        }
    }

    return 0;
}