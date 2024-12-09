#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<pair<int, int>> shows(n);
    for(int i = 0; i < n; i++) {
        cin >> shows[i].first >> shows[i].second;
    }

    sort(shows.begin(), shows.end());

    long long totalCost = 0;
    long long lastEnd = -1;

    for(int i = 0; i < n; i++) {
        if(lastEnd < shows[i].first) {
            totalCost = (totalCost + x + y * (shows[i].second - shows[i].first) % MOD) % MOD;
            lastEnd = shows[i].second;
        }
    }

    cout << totalCost << endl;

    return 0;
}