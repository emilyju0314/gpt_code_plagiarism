#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> stars(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        stars[i] = make_pair(x, y);
    }

    int minLines = n;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dx = stars[j].first - stars[i].first;
            int dy = stars[j].second - stars[i].second;
            int lines = 1;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                int dx2 = stars[k].first - stars[i].first;
                int dy2 = stars[k].second - stars[i].second;
                if (dx * dy2 == dy * dx2) lines++;
            }
            minLines = min(minLines, lines);
        }
    }

    cout << minLines << endl;

    return 0;
}