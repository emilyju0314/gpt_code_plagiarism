#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    unordered_map<int, int> prefix_sum_odd, prefix_sum_even;
    int sum_odd = 0, sum_even = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sum_even += weights[i];
        } else {
            sum_odd += weights[i];
        }

        prefix_sum_odd[i] = sum_odd;
        prefix_sum_even[i] = sum_even;
    }

    int count = 0;
    sum_odd = 0, sum_even = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (prefix_sum_odd[i] == prefix_sum_even[i] + sum_even) {
                count++;
            }
            sum_even += weights[i];
        } else {
            if (prefix_sum_odd[i] - weights[i] + sum_odd == prefix_sum_even[i]) {
                count++;
            }
            sum_odd += weights[i];
        }
    }

    cout << count << endl;

    return 0;
}