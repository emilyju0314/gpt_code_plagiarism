#include <iostream>
#include <vector>
#include <algorithm>

struct Segment {
    int x1, y1, x2, y2;
};

bool coordinateSort(const Segment& s1, const Segment& s2) {
    if (s1.x1 == s1.x2) return s1.x1 < s2.x1;
    return s1.y1 < s2.y1;
}

int countIntersections(std::vector<Segment>& segments) {
    std::sort(segments.begin(), segments.end(), coordinateSort);
    
    int intersections = 0;
    for (int i = 0; i < segments.size(); ++i) {
        for (int j = i+1; j < segments.size(); ++j) {
            if ((segments[j].x1 == segments[j].x2) && (segments[j].y1 > segments[i].y1) && (segments[j].y1 < segments[i].y2) &&
                (segments[i].x1 < segments[j].x1) && (segments[i].x2 > segments[j].x1)) {
                intersections++;
            }
        }
    }
    
    return intersections;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<Segment> segments(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> segments[i].x1 >> segments[i].y1 >> segments[i].x2 >> segments[i].y2;
    }
    
    int numIntersections = countIntersections(segments);
    std::cout << numIntersections << std::endl;
    
    return 0;
}