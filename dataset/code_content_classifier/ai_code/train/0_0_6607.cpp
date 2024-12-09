#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }

    int supercentralCount = 0;

    for(int i = 0; i < n; i++) {
        int x = points[i].first;
        int y = points[i].second;

        bool hasUpper = false, hasLower = false, hasLeft = false, hasRight = false;

        for(int j = 0; j < n; j++) {
            if(i != j) {
                int x2 = points[j].first;
                int y2 = points[j].second;

                if(x2 == x && y2 < y) {
                    hasUpper = true;
                } else if(x2 == x && y2 > y) {
                    hasLower = true;
                } else if(x2 < x && y2 == y) {
                    hasLeft = true;
                } else if(x2 > x && y2 == y) {
                    hasRight = true;
                }
            }
        }

        if(hasUpper && hasLower && hasLeft && hasRight) {
            supercentralCount++;
        }
    }

    cout << supercentralCount << endl;

    return 0;
}