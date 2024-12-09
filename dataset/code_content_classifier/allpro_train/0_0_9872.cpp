#include <iostream>
#include <vector>
#include <cmath>

// Structure to represent a line segment
struct LineSegment {
    int x1, y1, x2, y2;
};

// Function to check if two line segments intersect
bool doIntersect(LineSegment l1, LineSegment l2) {
    int o1 = (l2.y1 - l1.y1) * (l1.x2 - l1.x1) - (l2.x1 - l1.x1) * (l1.y2 - l1.y1);
    int o2 = (l2.y2 - l1.y1) * (l1.x2 - l1.x1) - (l2.x2 - l1.x1) * (l1.y2 - l1.y1);
    int o3 = (l1.y1 - l2.y1) * (l2.x2 - l2.x1) - (l1.x1 - l2.x1) * (l2.y2 - l2.y1);
    int o4 = (l1.y2 - l2.y1) * (l2.x2 - l2.x1) - (l1.x2 - l2.x1) * (l2.y2 - l2.y1);

    if ((o1 * o2 < 0) && (o3 * o4 < 0)) {
        return true; // Segments intersect
    }

    return false;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<LineSegment> lineSegments(N);
    
    // Input the line segment coordinates
    for (int i = 0; i < N; i++) {
        std::cin >> lineSegments[i].x1 >> lineSegments[i].y1 >> lineSegments[i].x2 >> lineSegments[i].y2;
    }

    int holes = 0;
    for (int i = 0; i < N; i++) {
        bool isHole = true;
        for (int j = 0; j < N; j++) {
            if (i != j && doIntersect(lineSegments[i], lineSegments[j])) {
                isHole = false;
                break;
            }
        }
        if (isHole) {
            holes++;
        }
    }

    std::cout << holes << std::endl;

    return 0;
}