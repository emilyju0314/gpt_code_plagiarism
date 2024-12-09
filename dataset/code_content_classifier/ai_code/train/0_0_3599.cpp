#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

bool isSameTriangle(vector<Point>& points, vector<Point>& triangle) {
    sort(points.begin(), points.end(), [](const Point& p1, const Point& p2) {
        return (p1.x < p2.x) || (p1.x == p2.x && p1.y < p2.y);
    });
    
    sort(triangle.begin(), triangle.end(), [](const Point& p1, const Point& p2) {
        return (p1.x < p2.x) || (p1.x == p2.x && p1.y < p2.y);
    });
    
    double d1 = distance(points[0], points[1]);
    double d2 = distance(points[0], points[2]);
    double d3 = distance(points[1], points[2]);
    
    vector<double> distances = {d1, d2, d3};
    
    do {
        double d1_t = distance(triangle[0], triangle[1]);
        double d2_t = distance(triangle[0], triangle[2]);
        double d3_t = distance(triangle[1], triangle[2]);
        
        vector<double> distances_t = {d1_t, d2_t, d3_t};
        
        sort(distances_t.begin(), distances_t.end());
        
        if(distances == distances_t) {
            return true;
        }
    } while(next_permutation(triangle.begin(), triangle.end()));
    
    return false;
}

int minColumnsToLand(vector<vector<Point>>& ships) {
    unordered_set<Point, pair_hash> columns;
    
    for(int i = 0; i < ships.size(); i++) {
        for(int j = i + 1; j < ships.size(); j++) {
            vector<Point> points = {ships[i][0], ships[i][1], ships[i][2]};
            vector<Point> triangle = {ships[j][0], ships[j][1], ships[j][2]};
            
            if(isSameTriangle(points, triangle)) {
                columns.insert(points.begin(), points.end());
            }
        }
    }
    
    return columns.size();
}

int main() {
    vector<vector<Point>> ships(4, vector<Point>(3));
    
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> ships[i][j].x >> ships[i][j].y;
        }
    }
    
    cout << minColumnsToLand(ships) << endl;
    
    return 0;
}