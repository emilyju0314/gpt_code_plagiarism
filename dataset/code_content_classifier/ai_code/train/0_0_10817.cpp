#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x, y;
};

struct Polygon {
    int score;
    std::vector<Point> vertices;
};

double intersection_area(Point A, Point B, double r) {
    double d = hypot(A.x - B.x, A.y - B.y);
    if (d >= 2 * r) return 0;
    
    double theta = 2 * acos(d / (2 * r));
    double sector_area = 0.5 * r * r * theta;
    double triangle_area = 0.5 * r * r * sin(theta);
    
    return sector_area - triangle_area;
}

int main() {
    int n, cx, cy, r;
    std::cin >> n >> cx >> cy >> r;
    
    double total_area = 0.0;
    std::vector<Polygon> polygons(n);
    
    for (int i = 0; i < n; i++) {
        int p, score;
        std::cin >> p >> score;
        
        polygons[i].score = score;
        
        for (int j = 0; j < p; j++) {
            Point vertex;
            std::cin >> vertex.x >> vertex.y;
            polygons[i].vertices.push_back(vertex);
        }
        
        // Calculate the area of each polygon
        double poly_area = 0.0;
        for (int j = 0; j < p; j++) {
            Point A = polygons[i].vertices[j];
            Point B = polygons[i].vertices[(j + 1) % p];
            poly_area += A.x * B.y - A.y * B.x;
        }
        poly_area = std::abs(poly_area) / 2.0;
        
        total_area += poly_area;
    }
    
    double total_intersection_area = 0.0;
    for (int i = 0; i < n; i++) {
        double poly_intersection_area = 0.0;
        int p = polygons[i].vertices.size();
        
        for (int j = 0; j < p; j++) {
            Point A = polygons[i].vertices[j];
            Point B = polygons[i].vertices[(j + 1) % p];
            poly_intersection_area += intersection_area(A, B, r);
        }
        
        total_intersection_area += poly_intersection_area;
    }
    
    double expected_score = 0.0;
    for (int i = 0; i < n; i++) {
        expected_score += (double)polygons[i].score * total_intersection_area / total_area;
    }
    
    std::cout << expected_score << std::endl;
    
    return 0;
}