#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<vector<pair<int, int>>> lines;
        for (int i = 0; i < n; i++) {
            int s;
            cin >> s;
            vector<pair<int, int>> stations;
            for (int j = 0; j < s; j++) {
                int x, y;
                cin >> x >> y;
                stations.push_back({x, y});
            }
            lines.push_back(stations);
        }

        int floors = 1;
        for (int i = 1; i < n; i++) {
            bool intersects = false;
            for (int j = 0; j < i; j++) {
                for (int k = 0; k < lines[i].size() - 1; k++) {
                    for (int l = 0; l < lines[j].size() - 1; l++) {
                        if (linesIntersect(lines[i][k], lines[i][k + 1], lines[j][l], lines[j][l + 1])) {
                            intersects = true;
                            break;
                        }
                    }
                    if (intersects) {
                        break;
                    }
                }
                if (intersects) {
                    break;
                }
            }
            if (intersects) {
                floors++;
            }
        }

        cout << floors << endl;
    }

    return 0;
}

bool linesIntersect(pair<int, int> p1, pair<int, int> q1, pair<int, int> p2, pair<int, int> q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4) {
        return true;
    }

    if (o1 == 0 && onSegment(p1, p2, q1)) {
        return true;
    }

    if (o2 == 0 && onSegment(p1, q2, q1)) {
        return true;
    }

    if (o3 == 0 && onSegment(p2, p1, q2)) {
        return true;
    }

    if (o4 == 0 && onSegment(p2, q1, q2)) {
        return true;
    }

    return false;
}

int orientation(pair<int, int> p, pair<int, int> q, pair<int, int> r) {
    int val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);
    if (val == 0) {
        return 0;
    }
    return (val > 0) ? 1 : 2;
}

bool onSegment(pair<int, int> p, pair<int, int> q, pair<int, int> r) {
    if (q.first <= max(p.first, r.first) && q.first >= min(p.first, r.first) &&
        q.second <= max(p.second, r.second) && q.second >= min(p.second, r.second)) {
        return true;
    }
    return false;
}