#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int W, H, N;
    cin >> W >> H >> N;

    vector<pair<int, int>> houses;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        houses.push_back(make_pair(x, y));
    }

    int min_time = INT_MAX;
    pair<int, int> optimal_point;

    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= H; j++) {
            int total_time = 0;
            for (auto& house : houses) {
                total_time += abs(i - house.first) + abs(j - house.second);
            }
            if (total_time < min_time) {
                min_time = total_time;
                optimal_point = make_pair(i, j);
            }
        }
    }

    cout << min_time << endl;
    cout << optimal_point.first << " " << optimal_point.second << endl;

    return 0;
}