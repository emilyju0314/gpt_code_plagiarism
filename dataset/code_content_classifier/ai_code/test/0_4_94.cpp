#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> denominations(n);
        for (int i = 0; i < n; i++) {
            cin >> denominations[i];
        }

        int min_s = INT_MAX;
        for (int i = 1; i <= k; i++) {
            int temp = i;
            bool possible = true;
            for (int j = n - 1; j >= 0; j--) {
                int count = temp / pow(10, denominations[j]);
                temp -= count * pow(10, denominations[j]);

                if (count > k) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                min_s = i;
                break;
            }
        }

        cout << min_s << endl;
    }

    return 0;
}