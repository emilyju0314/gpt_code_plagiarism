#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> guests;
    vector<int> favorites[n+1];
    vector<int> remaining(n+1, 2);

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        favorites[x].push_back(i);
        favorites[y].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        if (favorites[i].size() == 1) {
            guests.push_back({favorites[i][0], i});
        }
    }

    sort(guests.begin(), guests.end());

    int ans = 0;
    for (auto guest : guests) {
        int x = remaining[guest.second];
        remaining[guest.second]--;
        ans += x;
    }

    cout << ans << endl;

    return 0;
}