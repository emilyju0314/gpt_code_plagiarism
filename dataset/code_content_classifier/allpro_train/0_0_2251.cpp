#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

double triangleArea(const Point& p1, const Point& p2, const Point& p3) {
    return abs((p1.x*(p2.y - p3.y) + p2.x*(p3.y - p1.y) + p3.x*(p1.y - p2.y)) / 2.0);
}

double visibleArea(const vector<Point>& vertices) {
    double area = 0.0;
    for (int i = 1; i < vertices.size() - 1; i++) {
        area += triangleArea(vertices[0], vertices[i], vertices[i + 1]);
    }
    return area;
}

int main() {
    int N;
    cin >> N;
    
    vector<Point> vertices(N);
    
    for (int i = 0; i < N; i++) {
        cin >> vertices[i].x >> vertices[i].y;
    }
    
    double maxArea = 0.0;
    for (int i = 0; i < N; i++) {
        vector<Point> newVertices;
        for (int j = 0; j < N; j++) {
            newVertices.push_back({vertices[(i+j)%N].x, vertices[(i+j)%N].y});
        }
        double area = visibleArea(newVertices);
        maxArea = max(maxArea, area);
    }
    
    cout << fixed << maxArea << endl;
    
    return 0;
}