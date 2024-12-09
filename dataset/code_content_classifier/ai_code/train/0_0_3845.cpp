#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> cities;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        cities.push_back(make_pair(x, y));
    }

    sort(cities.begin(), cities.end());

    int max_distance = 0;
    for (int i = 1; i < n; i++) {
        max_distance += max(abs(cities[i].first - cities[i-1].first), abs(cities[i].second - cities[i-1].second));
    }

    max_distance += max(abs(cities[0].first - cities[n-1].first), abs(cities[0].second - cities[n-1].second));

    cout << max_distance << endl;

    return 0;
}