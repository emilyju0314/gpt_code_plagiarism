#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int min_moves_to_compact(vector<pair<pair<int, int>, pair<int, int>>> moles) {
    int min_moves = -1;
    for(int i = 0; i < 4; i++) {
        int x1 = moles[i].first.first;
        int y1 = moles[i].first.second;
        int x2 = moles[(i + 1) % 4].first.first;
        int y2 = moles[(i + 1) % 4].first.second;
        int x3 = moles[(i + 2) % 4].first.first;
        int y3 = moles[(i + 2) % 4].first.second;
        int a = moles[i].second.first;
        int b = moles[i].second.second;

        int d1x = x1 - a;
        int d1y = y1 - b;
        int d2x = x2 - a;
        int d2y = y2 - b;
        int d3x = x3 - a;
        int d3y = y3 - b;

        int area = abs(d1x * d2y - d1y * d2x) + abs(d2x * d3y - d2y * d3x) + abs(d3x * d1y - d3y * d1x);
        if(area != 0 && area % 2 == 0) {
            int moves = 0;
            if(d1x != 0 || d1y != 0) moves++;
            if(d2x != 0 || d2y != 0) moves++;
            if(d3x != 0 || d3y != 0) moves++;
            min_moves = min_moves == -1 ? moves : min(min_moves, moves);
        }
    }
    return min_moves;
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        vector<pair<pair<int, int>, pair<int, int>> moles;
        for(int j = 0; j < 4; j++) {
            int x, y, a, b;
            cin >> x >> y >> a >> b;
            moles.push_back({{x, y}, {a, b}});
        }
        cout << min_moves_to_compact(moles) << endl;
    }

    return 0;
}