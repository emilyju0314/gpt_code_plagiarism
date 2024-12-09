#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> barrels(n);
        for (int i = 0; i < n; i++) {
            cin >> barrels[i];
        }

        sort(barrels.begin(), barrels.end());

        int max_diff = 0;
        for (int i = 1; i <= k; i++) {
            max_diff = max(max_diff, barrels[n - i] - barrels[i - 1]);
        }

        cout << max_diff << endl;
    }

    return 0;
}