#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> initial_money(n);
    for (int i = 0; i < n; i++) {
        cin >> initial_money[i];
    }

    double total_expected_value = 0.0;

    for (int i = 0; i < q; i++) {
        int l, r;
        double p;
        cin >> l >> r >> p;

        double max_money_in_range = 0.0;
        for (int j = l - 1; j < r; j++) {
            max_money_in_range = max(max_money_in_range, (double)initial_money[j]);
        }

        total_expected_value += p * max_money_in_range;
    }

    cout << setprecision(9) << total_expected_value << endl;

    return 0;
}