#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x, y;
};

bool onSegment(Point p, Point q, Point r) {
    if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
        q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y))
        return true;
    return false;
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    
    if (o1 != o2 && o3 != o4)
        return true;
    
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

bool isInside(std::vector<Point>& polygon, Point p) {
    int n = polygon.size();
    if (n < 3) return false;

    Point extreme = {INT_MAX, p.y};

    int count = 0, i = 0;
    do {
        int next = (i + 1) % n;
        if (doIntersect(polygon[i], polygon[next], p, extreme)) {
            if (orientation(polygon[i], p, polygon[next]) == 0)
                return onSegment(polygon[i], p, polygon[next]);
            count++;
        }
        i = next;
    } while (i != 0);

    return count % 2 == 1;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        std::cin >> edges[i].first >> edges[i].second;
    }

    std::vector<Point> vertices(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vertices[i].x >> vertices[i].y;
    }

    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int k;
        std::cin >> k;
        
        std::vector<Point> cycle(k);
        for (int j = 0; j < k; j++) {
            int a;
            std::cin >> a;
            cycle[j] = vertices[a - 1];
        }
        
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (isInside(cycle, vertices[j])) {
                count++;
            }
        }
        std::cout << count << " ";
    }

    return 0;
}