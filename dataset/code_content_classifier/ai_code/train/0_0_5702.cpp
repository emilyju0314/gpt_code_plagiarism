#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x, y, index;
};

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2; 
}

void convexHull(std::vector<Point>& points, int n, int k) {
    if (n < 3) {
        std::cout << "NA\n";
        return;
    }

    std::vector<int> hull;
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    int p = l, q;
    do {
        hull.push_back(points[p].index);
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }
        p = q;
    } while (p != l);

    for (int i = 0; i < n; i++) {
        if (std::find(hull.begin(), hull.end(), points[i].index) == hull.end()) {
            hull.push_back(points[i].index);
        }
    }

    for (int i = 0; i < k; i++) {
        std::cout << hull[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int N, Q;
    std::cin >> N;

    std::vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        std::cin >> points[i].x >> points[i].y;
        points[i].index = i + 1;
    }

    std::cin >> Q;
    std::vector<int> questions(Q);
    for (int i = 0; i < Q; i++) {
        std::cin >> questions[i];
    }

    for (int q : questions) {
        convexHull(points, N, q);
    }

    return 0;
}