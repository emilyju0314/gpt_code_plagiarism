#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> segments(n);
    for (int i = 0; i < n; i++) {
        int xl, xr, y;
        cin >> xl >> xr >> y;
        segments[i] = {xl, xr};
    }

    sort(segments.begin(), segments.end());

    double ans = 0;
    for (int i = 0; i < n - 1; i++) {
        double diff = (double)(segments[i + 1].first - segments[i].second) / (segments[i + 1].first - segments[i].first);
        ans = max(ans, diff);
    }

    cout << fixed << setprecision(9) << ans << endl;

    return 0;
}