#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Building {
    int id, x, y, width, depth, height;

    bool operator<(const Building& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

int main() {
    int n, b = 1;
    while (cin >> n && n) {
        vector<Building> buildings;
        for (int i = 0; i < n; ++i) {
            Building building;
            cin >> building.x >> building.y >> building.width >> building.depth >> building.height;
            building.id = i + 1;
            buildings.push_back(building);
            // Add the reverse side of the building to the list
            building.x += building.width;
            building.y += building.depth;
            buildings.push_back(building);
        }

        sort(buildings.begin(), buildings.end());

        if (b > 1) cout << '\n';
        cout << "For map #" << b++ << ", the visible buildings are numbered as follows:\n";

        for (int i = 0; i < buildings.size(); ++i) {
            bool isVisible = true;
            for (int j = i + 1; j < buildings.size(); ++j) {
                if (buildings[j].y > buildings[i].y && buildings[j].height >= buildings[i].height &&
                    buildings[j].x < buildings[i].x + buildings[i].width && buildings[j].y < buildings[i].y + buildings[i].depth) {
                    isVisible = false;
                    break;
                }
            }
            if (isVisible) {
                cout << buildings[i].id << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}