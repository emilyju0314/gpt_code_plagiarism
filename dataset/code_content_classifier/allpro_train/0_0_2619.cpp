#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;

        long long min_product = LLONG_MAX;

        // Case 1: Decrease 'a' first
        long long a_diff = min(a - x, n);
        long long b_diff = min(b - max(y, b - n), n - a_diff);
        min_product = min(min_product, (a - a_diff) * (b - b_diff));

        // Case 2: Decrease 'b' first
        long long b_diff_2 = min(b - y, n);
        long long a_diff_2 = min(a - max(x, a - n), n - b_diff_2);
        min_product = min(min_product, (a - a_diff_2) * (b - b_diff_2));

        cout << min_product << endl;
    }

    return 0;
}