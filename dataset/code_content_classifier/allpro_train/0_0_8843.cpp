#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> antennas(n);
    for(int i = 0; i < n; i++) {
        cin >> antennas[i].first >> antennas[i].second;
    }

    sort(antennas.begin(), antennas.end());

    int needed = 0;
    int range = 0;
    for(int i = 0; i < n; i++) {
        if(antennas[i].first - antennas[i].second > range + 1) {
            needed += antennas[i].first - antennas[i].second - range - 1;
        }
        range = max(range, antennas[i].first + antennas[i].second);
    }

    if(range < m) {
        needed += m - range;
    }

    cout << needed << endl;

    return 0;
}