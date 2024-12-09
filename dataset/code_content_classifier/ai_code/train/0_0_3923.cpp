#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int x;
    cin >> x;

    vector<pair<int, int>> curses;
    for (int i = 0; i < n; i++) {
        int tl, tr, l, r;
        cin >> tl >> tr >> l >> r;
        curses.push_back({tl, l});
        curses.push_back({tr, r});
    }

    sort(curses.begin(), curses.end());

    int energy = 0;
    int alive = x;

    for (int i = 0; i < 2 * n; i++) {
        if (curses[i].second >= alive) {
            energy += abs(curses[i].second - alive);
            alive = curses[i].second;
        }
    }

    cout << energy << endl;

    return 0;
}