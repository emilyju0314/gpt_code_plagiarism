#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int r, n;
    cin >> r >> n;

    vector<pair<int, pair<int, int>>> celebs; // Pair of time and intersection (x, y)

    for (int i = 0; i < n; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        celebs.push_back({t, {x, y}});
    }

    sort(celebs.begin(), celebs.end());

    int maxCelebs = 0;
    int currX = 1, currY = 1;

    for (auto celeb : celebs) {
        int t = celeb.first;
        int x = celeb.second.first;
        int y = celeb.second.second;

        int timeToReach = abs(x - currX) + abs(y - currY);
        if (t >= timeToReach + 1) {
            maxCelebs++;
            currX = x;
            currY = y;
        }
    }

    cout << maxCelebs << endl;

    return 0;
}