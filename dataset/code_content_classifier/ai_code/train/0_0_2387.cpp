#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> max_h_diff(n);
    for (int i = 0; i < n - 1; i++) {
        max_h_diff[i] = abs(arr[i] - arr[i + 1]);
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int sum_lipschitz_constants = 0;
        for (int j = l; j < r; j++) {
            int curr_lipschitz_constant = max_h_diff[j];
            int max_diff = max(arr[l], arr[j + 1]) - min(arr[l], arr[j + 1]);
            curr_lipschitz_constant = min(curr_lipschitz_constant, max_diff);
            sum_lipschitz_constants += curr_lipschitz_constant;
        }

        cout << sum_lipschitz_constants << endl;
    }

    return 0;
}