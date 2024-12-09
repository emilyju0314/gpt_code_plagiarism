#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Location {
    int x, y, civilization;
};

bool onSameLine(Location a, Location b, Location c) {
    return (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) == 0;
}

int main() {
    int n;
    cin >> n;

    vector<Location> locations(n);
    for (int i = 0; i < n; i++) {
        cin >> locations[i].x >> locations[i].y >> locations[i].civilization;
    }

    vector<pair<int, int>> roads;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (locations[i].civilization == locations[j].civilization && !onSameLine(locations[i], locations[j], locations[0])) {
                roads.push_back({i, j});
            }
        }
    }

    if (roads.size() == 0) {
        cout << "Impossible" << endl;
    } else {
        cout << roads.size() << endl;
        for (auto road : roads) {
            cout << road.first << " " << road.second << endl;
        }
    }

    return 0;
}