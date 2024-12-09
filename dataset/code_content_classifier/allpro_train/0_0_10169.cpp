#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

#define MOD 1000000007

using namespace std;

struct Point {
    int x, y;
};

long long cross_product(const Point& O, const Point& A, const Point& B) {
    return 1LL * (A.x - O.x) * (B.y - O.y) - 1LL * (A.y - O.y) * (B.x - O.x);
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    long long count = 0;
    for (int i = 0; i < n; i++) {
        map<long long, int> slopes;
        vector<pair<long long, long long>> lines;

        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            long long dx = points[j].x - points[i].x;
            long long dy = points[j].y - points[i].y;

            long long gcd = __gcd(abs(dx), abs(dy));
            dx /= gcd;
            dy /= gcd;

            if (dy < 0 || (dy == 0 && dx < 0)) {
                dx = -dx;
                dy = -dy;
            }

            slopes[dx * MOD + dy]++;

            long long c1 = cross_product({0, 0}, {points[i].x + dx, points[i].y + dy}, points[i]);
            long long c2 = cross_product({0, 0}, {points[i].x - dx, points[i].y - dy}, points[i]);

            lines.push_back({c1, c2});
        }

        sort(lines.begin(), lines.end());
        
        int cnt = 0;
        for (int j = 0; j < n - 1; j++) {
            if (j > 0 && lines[j] == lines[j - 1]) {
                cnt++;
                count = (count + cnt) % MOD;
            } else {
                cnt = 1;
                count = (count + 1) % MOD;
            }
        }
        
        for (auto& [slope, freq] : slopes) {
            count = (count + 1LL * freq * (freq - 1) / 2) % MOD;
        }
    }

    cout << count << endl;

    return 0;
}