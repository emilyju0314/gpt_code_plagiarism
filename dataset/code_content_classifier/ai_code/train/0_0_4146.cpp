#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool checkPattern(vector<pair<int, int>> positions) {
    set<pair<int, int>> uniquePositions;
    int cx = 0, cy = 0;
    for (int i = 0; i < positions.size(); i++) {
        if (uniquePositions.count(positions[i]) > 0) return false;
        uniquePositions.insert(positions[i]);

        cx += positions[i].first;
        cy += positions[i].second;
    }

    return (cx % 4 == 0 && cy % 4 == 0);
}

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    vector<vector<int>> relativePositions = {{1, 0}, {2, 0}, {3, 0},
                                             {-3, 1}, {-2, 1}, {-1, 1}, {0, 1}, {1, 1}, {2, 1}, {3, 1},
                                             {-3, 2}, {-2, 2}, {-1, 2}, {0, 2}, {1, 2}, {2, 2}, {3, 2},
                                             {-3, 3}, {-2, 3}, {-1, 3}, {0, 3}, {1, 3}, {2, 3}, {3, 3}};

    while (true) {
        cin >> x1;
        if (x1 > 4) break;

        vector<pair<int, int>> positions;
        positions.emplace_back(x1, y1);
        cin >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        positions.emplace_back(x2, y2);
        positions.emplace_back(x3, y3);
        positions.emplace_back(x4, y4);

        int count = 0;
        for (const auto &relativePos : relativePositions) {
            vector<pair<int, int>> pattern;
            for (auto &position : positions) {
                pattern.emplace_back(position.first + relativePos.first, position.second + relativePos.second);
            }
            if (checkPattern(pattern)) count++;
        }

        cout << count << endl;
    }

    return 0;
}