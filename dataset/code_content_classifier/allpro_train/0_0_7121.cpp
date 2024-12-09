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

        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        vector<pair<int, int>> delivery;
        vector<int> pickup;

        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                delivery.push_back({a[i], b[i]});
            } else {
                pickup.push_back(b[i]);
            }
        }

        sort(delivery.begin(), delivery.end());

        int minTime = 0;
        int currentTime = 0;

        for (auto d : delivery) {
            currentTime += d.first;
            minTime = max(minTime, currentTime);
            currentTime += d.second - d.first;
        }

        for (int p : pickup) {
            currentTime += p;
            minTime = max(minTime, currentTime);
        }

        cout << minTime << endl;
    }

    return 0;
}