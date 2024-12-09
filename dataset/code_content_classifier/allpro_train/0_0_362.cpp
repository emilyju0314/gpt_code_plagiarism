#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        vector<pair<int, int>> app;
        for (int i = 0; i < n; i++) {
            app.push_back({b[i], a[i]});
        }

        sort(app.begin(), app.end());

        long long sum = 0;
        int ans = 0;
        int left = n;
        for (int i = 0; i < n; i++) {
            int mem = app[i].second;
            int points = app[i].first;

            if (sum + mem <= m) {
                sum += mem;
                ans += points;
                left--;
            } else {
                break;
            }
        }

        if (sum >= m) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}