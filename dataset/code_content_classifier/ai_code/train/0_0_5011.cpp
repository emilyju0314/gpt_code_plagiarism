#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define PI 3.14159265358979323846

struct Circle {
    int x, y, r;
};

double angle_diff(double a1, double a2) {
    double diff = a1 - a2;
    while (diff <= -PI) diff += 2 * PI;
    while (diff > PI) diff -= 2 * PI;
    return fabs(diff);
}

void update_angles(std::vector<std::pair<double, bool>>& angles, double& r, double a1, double a2) {
    double diff = angle_diff(a1, a2);
    if (diff < 1e-7 || diff > PI - 1e-7) return;
    double phi = acos((2 * r * r - 2 * r * r * cos(diff)) / (2 * r * r));
    double s1 = a1 - atan2(sin(phi), cos(phi) - r);
    double s2 = a1 - atan2(sin(-phi), cos(-phi) - r);
    double e1 = a2 - atan2(sin(phi), cos(phi) - r);
    double e2 = a2 - atan2(sin(-phi), cos(-phi) - r);
    angles.push_back({s1, true});
    angles.push_back({e1, false});
    angles.push_back({s2, true});
    angles.push_back({e2, false});
    if (s1 > e1) {
        angles.push_back({atan2(sin(phi), r - cos(phi)), false});
    }
    if (s2 > e2) {
        angles.push_back({atan2(sin(-phi), r - cos(-phi)), false});
    }
}

double perimeter(const std::vector<Circle>& circles, double r) {
    std::vector<std::pair<double, bool>> angles;
    for (const auto& c1 : circles) {
        std::vector<double> c_angles;
        for (const auto& c2 : circles) {
            if (&c1 == &c2) continue;
            double dist = sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
            if (dist <= c1.r + c2.r) {
                double angle = atan2(c2.y - c1.y, c2.x - c1.x);
                double a1 = angle - asin(c2.r / dist);
                double a2 = angle + asin(c2.r / dist);
                c_angles.push_back(a1);
                c_angles.push_back(a2);
            }
        }
        std::sort(c_angles.begin(), c_angles.end());
        for (size_t i = 0; i < c_angles.size(); i += 2) {
            update_angles(angles, r, c_angles[i], c_angles[i + 1]);
        }
    }
    std::sort(angles.begin(), angles.end());

    double length = 0.0;
    int count = 1;
    for (size_t i = 0; i < angles.size(); ++i) {
        if (count == 0) length += angles[i].first - angles[i - 1].first;
        if (angles[i].second) {
            count++;
        } else {
            count--;
        }
    }
    length += 2 * PI * r;

    return length;
}

int main() {
    int n, r;
    while (std::cin >> n >> r && n != 0 && r != 0) {
        std::vector<Circle> circles(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> circles[i].x >> circles[i].y >> circles[i].r;
        }
        double result = perimeter(circles, r);
        std::cout << result << std::endl;
    }

    return 0;
}