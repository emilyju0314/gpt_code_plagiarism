#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> cities(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        cities[i] = make_pair(x, y);
    }

    sort(cities.begin(), cities.end());

    int total_cost = 0;
    for (int i = 0; i < N-1; i++) {
        total_cost += max(abs(cities[i].first - cities[i+1].first), abs(cities[i].second - cities[i+1].second));
    }

    cout << total_cost << endl;

    return 0;
}