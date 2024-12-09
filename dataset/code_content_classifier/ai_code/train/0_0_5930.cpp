#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, s;
    cin >> n >> k >> s;

    vector<int> loquacity(n);
    for (int i = 0; i < n; i++) {
        cin >> loquacity[i];
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        vector<int> current_loquacity(loquacity.begin(), loquacity.begin() + k);
        int swaps = min(s, i);
        sort(current_loquacity.begin(), current_loquacity.end());
        int loquacity_sum = 0;
        for (int j = 0; j < k; j++) {
            loquacity_sum += current_loquacity[j];
        }
        result = max(result, loquacity_sum);

        if (i < n - 1) {
            int temp = loquacity[i];
            loquacity[i] = loquacity[i+1];
            loquacity[i+1] = temp;
        }
    }

    cout << result << endl;

    return 0;
}