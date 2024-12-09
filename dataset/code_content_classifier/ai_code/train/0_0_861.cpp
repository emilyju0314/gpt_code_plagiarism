#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_set<int> points;
    vector<pair<int, int>> obstacles;

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                points.insert(x * 1000000000 + y);
            }
        }
        
        obstacles.push_back({x1, y1});
        obstacles.push_back({x2, y2});
    }

    int count = 0;
    for (auto point : points) {
        int x = point / 1000000000;
        int y = point % 1000000000;

        bool canHide = true;
        for (int i = 0; i < obstacles.size(); i += 2) {
            if (obstacles[i].first < x && obstacles[i + 1].first > x && obstacles[i].second < y && obstacles[i + 1].second > y) {
                canHide = false;
                break;
            }
        }

        if (canHide) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}