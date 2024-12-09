#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }

        sort(d.begin(), d.end());

        long long min_cost = 0;
        for (int i = 1; i < n; i++) {
            min_cost += 1LL * (d[i] - d[i-1]) * (n - i) * i;
        }

        cout << min_cost << endl;
    }

    return 0;
}