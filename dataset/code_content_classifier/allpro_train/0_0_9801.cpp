#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        long long k, n, a, b;
        cin >> k >> n >> a >> b;

        if (n * b >= k) {
            cout << -1 << "\n";
            continue;
        }

        long long max_turns = min(n, (k - 1) / (a - b));
        long long remaining = k - max_turns * a;
        long long play_turns = (remaining + (a - 1) - 1) / (a - 1);

        cout << max_turns - play_turns << "\n";
    }

    return 0;
}