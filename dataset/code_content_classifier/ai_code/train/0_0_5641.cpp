#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> points(n);
    map<int, vector<pair<int, int>>> xs, ys;

    for (int i = 0; i < n; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        points[i] = make_tuple(x, y, c);
        xs[x+y].push_back({x, y});
        ys[y-x].push_back({x, y});
    }

    long long max_score = LLONG_MIN;
    int x1, y1, x2, y2;

    for (auto& [k, v] : xs) {
        sort(v.begin(), v.end());
        long long score = 0;
        int left, right = 0;
        
        for (int i = 0; i < v.size(); ++i) {
            while (right < v.size() && v[right].first - v[i].first <= 0) {
                score += v[right].second;
                right++;
            }
            if (i > 0) {
                score -= v[i-1].second;
            }

            if (score > max_score) {
                max_score = score;
                x1 = v[i].first;
                y1 = v[i].first;
                x2 = v[i].first;
                y2 = v[right-1].second;
            }
        }
    }

    cout << max_score << endl;
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

    return 0;
}