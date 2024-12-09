#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(double c, const vector<pair<int, int>>& problems) {
    double max_points = 0;
    double curr_points = 0;
    double sum_t = 0;

    for (const auto& p : problems) {
        sum_t += p.second;
        curr_points += p.first - c * sum_t;
        max_points = max(max_points, curr_points);
        if (curr_points < 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    vector<int> t(n);
    vector<pair<int, int>> problems;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> t[i];
        problems.push_back({p[i], t[i]});
    }

    double l = 0, r = 1e9;

    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2;
        if (check(mid, problems)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << l << endl;

    return 0;
}