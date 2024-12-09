#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> powers(n);
    for (int i = 0; i < n; i++) {
        cin >> powers[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += powers[i];
        if (i > 0 && sum == powers[i]) {
            powers[i] += powers[i - 1];
        }
    }

    for (int i = 0; i < q; i++) {
        int p, x;
        cin >> p >> x;
        p--;

        if (p > 0) {
            int prev_power = powers[p] - powers[p - 1];
            int next_power = p < n - 1 ? powers[p + 1] - powers[p] : 0;
            if (prev_power == prev_power + next_power) {
                powers[p] = prev_power + next_power;
            } else {
                powers[p] = x;
            }
        } else {
            int next_power = p < n - 1 ? powers[p + 1] - powers[p] : 0;
            if (powers[p] == powers[p] + next_power) {
                powers[p] = powers[p] + next_power;
            } else {
                powers[p] = x;
            }
        }

        int king_shaman_index = -1;
        for (int j = 0; j < n; j++) {
            if (j > 0 && powers[j] == powers[j] + powers[j - 1]) {
                king_shaman_index = j + 1;
                break;
            }
        }

        cout << king_shaman_index << endl;
    }

    return 0;
}