#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n, t, q;
    cin >> n >> t >> q;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    int total_tickets = 0;
    vector<int> count(n);

    auto get_expected_value = [&]() {
        double expected_value = 0;
        for (int i = 0; i < n; i++) {
            double prob_win = (double)count[i] / (total_tickets + t);
            expected_value += prob_win * p[i];
        }
        return expected_value;
    };

    cout << fixed << setprecision(9);

    for (int i = 0; i < q; i++) {
        int tk, rk;
        cin >> tk >> rk;
        rk--;

        if (tk == 1) {
            if (total_tickets + t == 0) {
                count[rk] += t;
                total_tickets += t;
            } else {
                int low = 0, high = t;
                while (high - low > 1) {
                    int mid = (low + high) / 2;
                    if (count[rk] + mid <= (total_tickets + t) / 2) {
                        low = mid;
                    } else {
                        high = mid;
                    }
                }
                count[rk] += low;
                total_tickets += low;
            }
        } else {
            total_tickets--;
            count[rk]--;
        }

        cout << get_expected_value() << endl;
    }

    return 0;
}