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

        vector<pair<int, int>> dishes;
        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) {
            int ai, bi;
            cin >> ai >> bi;
            dishes.push_back({ai, bi});
            a[i] = ai;
            b[i] = bi;
        }

        sort(dishes.begin(), dishes.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first - a.second < b.first - b.second;
        });

        int balance = 0;
        for (int i = 0; i < n; i++) {
            balance += abs(a[i] - b[i]);
        }

        cout << balance << endl;

        for (int i = 0; i < n; i++) {
            int x = min(a[i], m);
            int y = m - x;
            cout << x << " " << y << endl;
        }
    }

    return 0;
}