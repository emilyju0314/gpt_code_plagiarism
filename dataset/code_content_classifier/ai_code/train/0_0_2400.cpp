#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    vector<pair<int, int>> planes(n);
    for (int i = 0; i < n; i++) {
        cin >> planes[i].first >> planes[i].second;
    }

    sort(planes.begin(), planes.end());

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (planes[j].first - planes[i].first <= planes[i].second + w && planes[j].first - planes[i].first >= planes[i].second - w) {
                ans++;
            } else {
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}