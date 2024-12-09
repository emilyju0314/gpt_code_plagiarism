#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct point {
    double x, y;
};

int n, k;
vector<pair<point, double>> circles;
vector<point> intersections;

double dist(point a, point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

bool isInsideCircle(point p, point center, double radius) {
    return dist(p, center) <= radius;
}

int main() {
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        double x, y, r;
        cin >> x >> y >> r;
        circles.push_back({{x, y}, r});
    }

    // Calculate intersection points
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            double d = dist(circles[i].first, circles[j].first);

            // No intersection
            if(d >= circles[i].second + circles[j].second) continue;

            // One circle is inside the other
            if(d <= abs(circles[i].second - circles[j].second)) continue;

            double a = (circles[i].second * circles[i].second - circles[j].second * circles[j].second + d * d) / (2 * d);
            double h = sqrt(circles[i].second * circles[i].second - a * a);

            point p;
            p.x = circles[i].first.x + a * (circles[j].first.x - circles[i].first.x) / d;
            p.y = circles[i].first.y + a * (circles[j].first.y - circles[i].first.y) / d;

            double dx = h * (circles[j].first.y - circles[i].first.y) / d;
            double dy = h * (circles[j].first.x - circles[i].first.x) / d;

            point p1 = {p.x + dx, p.y - dy};
            point p2 = {p.x - dx, p.y + dy};

            intersections.push_back(p1);
            intersections.push_back(p2);
        }
    }

    int ans = n;
    for(auto p1 : intersections) {
        for(auto p2 : intersections) {
            if(p1.x == p2.x && p1.y == p2.y) continue;
            int cnt = 0;
            for(auto circle : circles) {
                if(isInsideCircle(p1, circle.first, circle.second)) cnt++;
                if(isInsideCircle(p2, circle.first, circle.second)) cnt++;
            }
            ans = max(ans, cnt);
        }
    }

    cout << ans << endl;

    return 0;
}