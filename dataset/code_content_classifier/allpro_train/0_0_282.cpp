#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> vertical_cuts;
    vector<pair<int, int>> horizontal_cuts;

    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            vertical_cuts.emplace_back(min(y1, y2), max(y1, y2));
        } else {
            horizontal_cuts.emplace_back(min(x1, x2), max(x1, x2));
        }
    }

    sort(vertical_cuts.begin(), vertical_cuts.end());
    sort(horizontal_cuts.begin(), horizontal_cuts.end());

    long long v_empty = n - 1, h_empty = m - 1;

    for (const auto& p : vertical_cuts) {
        v_empty -= p.second - p.first;
    }

    for (const auto& p : horizontal_cuts) {
        h_empty -= p.second - p.first;
    }

    bool first_wins = ((v_empty % 2 == 1) ^ (h_empty % 2 == 1));

    if (!first_wins) {
        cout << "SECOND" << endl;
    } else {
        cout << "FIRST" << endl;

        if (v_empty % 2 == 1) {
            int remaining = h_empty;
            int y = 0;
            for (const auto& p : horizontal_cuts) {
                if (p.first - y > 0) {
                    cout << "0 " << y << " 0 " << y + remaining << endl;
                    return 0;
                } else {
                    y = p.second;
                }
            }
            cout << "0 " << y << " 0 " << m - 1 - y << endl;
        } else {
            int remaining = v_empty;
            int x = 0;
            for (const auto& p : vertical_cuts) {
                if (p.first - x > 0) {
                    cout << x << " 0 " << x + remaining << " 0" << endl;
                    return 0;
                } else {
                    x = p.second;
                }
            }
            cout << x << " 0 " << n - 1 - x << " 0" << endl;
        }
    }

    return 0;
}