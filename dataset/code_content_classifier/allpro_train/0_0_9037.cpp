#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> a(n-2);
    for(int i = 0; i < n-2; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> stations(n);
    for(int i = 0; i < n; i++) {
        cin >> stations[i].first >> stations[i].second;
    }

    int total_time = 0;

    for(int i = 1; i < n - 1; i++) {
        int dist = abs(stations[n-1].first - stations[i].first) + abs(stations[n-1].second - stations[i].second);
        total_time += d * dist + a[i-1];
    }

    cout << total_time << endl;

    return 0;
}