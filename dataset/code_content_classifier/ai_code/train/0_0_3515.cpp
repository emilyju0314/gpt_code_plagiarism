#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int G, S;
    cin >> G >> S;

    vector<pair<int, int>> roads[M];
    vector<int> lowest_cost(N + 1, INT_MAX);

    for (int i = 0; i < M; i++) {
        int xi, yi, gi, si;
        cin >> xi >> yi >> gi >> si;
        roads[i] = {xi, yi, gi, si};
    }

    for (int i = 0; i < M; i++) {
        int xi = roads[i].first;
        int yi = roads[i].second;
        int gi = roads[i].third;
        int si = roads[i].fourth;

        int current_cost = max(gi * G, si * S);
        lowest_cost[xi] = min(lowest_cost[xi], current_cost);
        lowest_cost[yi] = min(lowest_cost[yi], current_cost);
    }

    int max_cost = *max_element(lowest_cost.begin() + 1, lowest_cost.end());
    if (max_cost == INT_MAX) {
        cout << "<image>" << endl;
    } else {
        cout << max_cost << endl;
    }

    return 0;
}