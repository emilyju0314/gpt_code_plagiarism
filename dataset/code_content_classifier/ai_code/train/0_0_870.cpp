#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Location {
    int x, y, civilization;
};

bool areConnected(const Location& a, const Location& b) {
    return a.civilization == b.civilization;
}

bool noIntersections(const Location& a, const Location& b, const Location& c, const Location& d) {
    int det = (b.x - a.x) * (d.y - c.y) - (d.x - c.x) * (b.y - a.y);
    if (det == 0) {
        return false; // the two roads are parallel
    }
    
    double t = ((c.x - a.x) * (d.y - c.y) - (c.y - a.y) * (d.x - c.x)) / static_cast<double>(det);
    double u = ((c.y - a.y) * (b.x - a.x) - (c.x - a.x) * (b.y - a.y)) / static_cast<double>(det);
    
    return t >= 0 && t <= 1 && u >= 0 && u <= 1;
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
            if (areConnected(locations[i], locations[j])) {
                bool validRoad = true;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j && areConnected(locations[i], locations[k])) {
                        if (noIntersections(locations[i], locations[j], locations[i], locations[k])) {
                            validRoad = false;
                            break;
                        }
                    }
                }
                if (validRoad) {
                    roads.push_back({i, j});
                }
            }
        }
    }
    
    if (roads.empty()) {
        cout << "Impossible" << endl;
    } else {
        cout << roads.size() << endl;
        for (auto road : roads) {
            cout << road.first << " " << road.second << endl;
        }
    }
    
    return 0;
}