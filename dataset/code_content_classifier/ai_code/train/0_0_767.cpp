#include <iostream>
#include <vector>

struct Point {
    double x, y;
};

struct Segment {
    Point p, q;
};

bool onSegment(Point p, Point q, Point r) {
    if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
        q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y)) {
        return true;
    }
    return false;
}

int orientation(Point p, Point q, Point r) {
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
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

int main() {
    int k;
    while (std::cin >> k && k != 0) {
        std::vector<Segment> segments;
        for (int i = 0; i < k; ++i) {
            Segment newSegment;
            std::cin >> newSegment.p.x >> newSegment.p.y >> newSegment.q.x >> newSegment.q.y;
            for (int j = segments.size() - 1; j >= 0; --j) {
                if (doIntersect(newSegment.p, newSegment.q, segments[j].p, segments[j].q)) {
                    segments.erase(segments.begin() + j); // Remove overlapping segment
                }
            }
            segments.push_back(newSegment);
        }

        Point pinhole;
        std::cin >> pinhole.x >> pinhole.y;

        int pinholes = 0;
        for (const auto& segment : segments) {
            if (doIntersect(segment.p, segment.q, pinhole, {pinhole.x, 101})) {
                pinholes++;
            }
        }

        std::cout << pinholes << std::endl;
    }

    return 0;
}