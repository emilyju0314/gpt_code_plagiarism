#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    bool first = true;

    while (cin >> n) {
        if (n == 0) {
            break;
        }

        if (!first) {
            cout << endl;
        }
        first = false;

        vector<int> a(n), b(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        vector<int> sums;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                sums.push_back(a[i] + b[j]);
            }
        }

        sort(sums.begin(), sums.end());

        int q;
        cin >> q;

        cout << "Case " << 1 << ":" << endl;

        for (int i = 0; i < q; ++i) {
            int query;
            cin >> query;

            int closest_sum = -1;
            int min_diff = numeric_limits<int>::max();

            for (int sum : sums) {
                if (abs(sum - query) < min_diff) {
                    closest_sum = sum;
                    min_diff = abs(sum - query);
                }
            }

            cout << "Closest sum to " << query << " is " << closest_sum << "." << endl;
        }
    }

    return 0;
}
