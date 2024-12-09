#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> colors[3];
    map<pair<int, int>, int> mark;

    for (int i = 0; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x += 300000;
        y += 300000;
        colors[c-1].push_back({x, y});
        mark[{x, y}] = c;
    }

    int ans = 0;
    for (int a = 0; a < 3; a++) {
        for (int b = a + 1; b < 3; b++) {
            vector<pair<int, int>> inter;
            vector<pair<int, int>> left;
            vector<pair<int, int>> right;

            for (auto x : colors[a]) {
                if (mark[{x.first, x.second}] == b + 1) {
                    inter.push_back(x);
                } else {
                    left.push_back(x);
                }
            }

            for (auto x : colors[b]) {
                if (mark[{x.first, x.second}] == a + 1) {
                    inter.push_back(x);
                } else {
                    right.push_back(x);
                }
            }

            sort(inter.begin(), inter.end());
            sort(left.begin(), left.end());
            sort(right.begin(), right.end());

            pair<int, int> upto_left = {-1, -1};
            pair<int, int> upto_right = {-1, -1};

            vector<pair<int, int>> filtered_left;
            for (auto x : left) {
                if (x.second >= upto_left.second) {
                    upto_left = x;
                    filtered_left.push_back(x);
                }
            }

            vector<pair<int, int>> filtered_right;
            for (auto x : right) {
                if (x.second >= upto_right.second) {
                    upto_right = x;
                    filtered_right.push_back(x);
                }
            }

            ans = max(ans, (int)filtered_left.size() + (int)filtered_right.size() + (int)inter.size());
        }
    }

    cout << ans << endl;

    return 0;
}