#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> points(n);

        for(int i = 0; i < n; i++) {
            cin >> points[i].first;
        }

        for(int i = 0; i < n; i++) {
            cin >> points[i].second;
        }

        sort(points.begin(), points.end());

        int ans = 0;

        for(int i = 0; i < n - 1; i++) {
            if(points[i].first % 2 == 0 && points[i].second % 2 != 0) {
                ans += points[i+1].first - points[i].first;
            } else if(points[i].first % 2 != 0 && points[i].second % 2 == 0) {
                ans += points[i+1].first - points[i].first;
            }
        }

        cout << ans << endl;
    }

    return 0;
}