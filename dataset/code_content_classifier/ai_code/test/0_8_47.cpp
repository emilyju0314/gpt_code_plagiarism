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

        vector<int> depots(n);
        for (int i = 0; i < n; i++) {
            cin >> depots[i];
        }

        sort(depots.begin(), depots.end());

        long long total_distance = 0;
        int i = n - 1;
        while (i >= 0) {
            total_distance += 2 * depots[i];
            i -= k;
        }

        cout << total_distance << endl;
    }

    return 0;
}