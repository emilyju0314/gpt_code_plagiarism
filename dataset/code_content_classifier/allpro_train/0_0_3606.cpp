#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, w, h;
    cin >> n >> w >> h;

    vector<pair<int, pair<int, int>>> dancers; // {group, {position, waiting time}}

    for (int i = 0; i < n; i++) {
        int g, p, t;
        cin >> g >> p >> t;
        dancers.push_back({g, {p, t}});
    }

    vector<pair<int, int>> result; // {x, y} stopping positions of dancers

    for (int i = 0; i < n; i++) {
        int g = dancers[i].first;
        int p = dancers[i].second.first;
        int t = dancers[i].second.second;

        int x = p, y = 0;

        if (g == 1) {
            y = h;
            y -= t;
            if ((p + t) % (2 * w) >= w) {
                x = w - (p + t) % w;
            }
        } else {
            x = w;
            x -= t;
            if ((p + t) % (2 * h) >= h) {
                y = h - (p + t) % h;
            }
        }

        result.push_back({x, y});
    }

    for (int i = 0; i < n; i++) {
        cout << result[i].first << " " << result[i].second << endl;
    }

    return 0;
}