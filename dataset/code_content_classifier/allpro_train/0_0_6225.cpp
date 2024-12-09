#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<pair<int, int>> bottoms;
        vector<pair<int, int>> tops;

        for (int i = 0; i < n; i++) {
            int x, y;
            char dir;
            cin >> x >> y >> dir;
            if (dir == 'x') {
                bottoms.push_back({x, y});
                tops.push_back({x+1, y});
            } else {
                bottoms.push_back({x, y});
                tops.push_back({x, y+1});
            }
        }

        sort(bottoms.begin(), bottoms.end());
        sort(tops.begin(), tops.end());

        bool possible = true;

        for (int i = 0; i < n-1; i++) {
            if (tops[i].first > bottoms[i+1].first || tops[i].second > bottoms[i+1].second) {
                possible = false;
                break;
            }
        }

        cout << (possible ? "Yes" : "No") << endl;
    }

    return 0;
}