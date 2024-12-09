#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> balls;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        balls.push_back({x, y});
    }

    unordered_set<pair<int, int>> seen;
    int min_cost = N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(i == j) continue;

            int dx = balls[j].first - balls[i].first;
            int dy = balls[j].second - balls[i].second;

            seen.clear();
            int cost = N - 1;
            for (int k = 0; k < N; k++) {
                int x = balls[k].first - dx;
                int y = balls[k].second - dy;
                if(seen.count({x, y}) || (x == balls[k].first && y == balls[k].second)) {
                    cost--;
                }
                seen.insert({balls[k].first, balls[k].second});
            }

            min_cost = min(min_cost, cost);
        }
    }

    cout << min_cost << endl;

    return 0;
}