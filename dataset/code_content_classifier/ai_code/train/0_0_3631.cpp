#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

struct Point {
    double x, y;
};

struct LineSegment {
    Point start, end;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double calculateLength(std::vector<LineSegment>& segments) {
    double totalLength = 0;
    for (int i = 0; i < segments.size(); i++) {
        totalLength += distance(segments[i].start, segments[i].end);
    }

    return totalLength;
}

int main() {
    int caseNum = 0;
    
    while (true) {
        int n;
        std::cin >> n;
        
        if (n == 0) break;
        
        std::vector<LineSegment> segments(n);
        
        for (int i = 0; i < n; i++) {
            std::cin >> segments[i].start.x >> segments[i].start.y >> segments[i].end.x >> segments[i].end.y;
        }
        
        double minLength = calculateLength(segments);
        
        caseNum++;
        std::cout << "Case " << caseNum << ": " << std::fixed << std::setprecision(5) << minLength << std::endl;
    }

    return 0;
}