#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> segments(n);
    for (int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
    }

    for (int i = 0; i < m; i++) {
        int cnt;
        cin >> cnt;

        vector<int> points(cnt);
        for (int j = 0; j < cnt; j++) {
            cin >> points[j];
        }

        int ans = 0;
        for (int j = 0; j < n; j++) {
            bool containsAllPoints = true;
            for (int k = 0; k < cnt; k++) {
                if (points[k] < segments[j].first || points[k] > segments[j].second) {
                    containsAllPoints = false;
                    break;
                }
            }
            if (containsAllPoints) {
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}