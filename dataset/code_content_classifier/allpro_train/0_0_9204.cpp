#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> offers(m);
    for (int i = 0; i < m; i++) {
        cin >> offers[i].first >> offers[i].second;
    }

    vector<int> daysOccupied(n+1, 0);
    vector<int> cnt(n+1, 0);

    for (int x = 1; x <= n; x++) {
        for (auto offer : offers) {
            if (offer.second - offer.first + 1 >= x) {
                cnt[offer.first]++;
                cnt[offer.second + 1]--;
            }
        }

        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += cnt[i];
            daysOccupied[x] = max(daysOccupied[x], sum);
        }

        fill(cnt.begin(), cnt.end(), 0);
    }

    for (int i = 1; i <= n; i++) {
        cout << daysOccupied[i] << endl;
    }

    return 0;
}