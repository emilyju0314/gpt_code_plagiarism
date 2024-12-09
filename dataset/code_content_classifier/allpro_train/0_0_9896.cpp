#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<Point> detachments(n);
    for (int i = 0; i < n; i++) {
        cin >> detachments[i].x >> detachments[i].y;
    }

    int min_t = INT_MAX;
    for (int i = 0; i < n; i++) {
        vector<int> dist;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            dist.push_back(abs(detachments[i].x - detachments[j].x) + abs(detachments[i].y - detachments[j].y));
        }
        sort(dist.begin(), dist.end());
        int t = dist.back();
        for (int j = 0; j < n-1; j++) {
            t = gcd(t, dist[j]);
        }
        min_t = min(min_t, t);
    }

    vector<pair<int, int>> dist;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            dist.push_back({abs(detachments[i].x - detachments[j].x), abs(detachments[i].y - detachments[j].y)});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int x = detachments[i].x + detachments[j].x;
            int y = detachments[i].y + detachments[j].y;

            bool valid = true;
            for (const auto& d : dist) {
                if (abs(x - d.first) + abs(y - d.second) > min_t) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                min_t = min(min_t, max(abs(x), abs(y)));
            }
        }
    }

    if (min_t == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_t << endl;
    }

    return 0;
}