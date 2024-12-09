#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

struct Point {
    double x, y;
};

struct Building {
    std::vector<Point> vertices;
};

double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool isInside(Point p, Building building) {
    int crosses = 0;
    for (int i = 0, j = building.vertices.size() - 1; i < building.vertices.size(); j = i++) {
        if (((building.vertices[i].y > p.y) != (building.vertices[j].y > p.y)) &&
            (p.x < (building.vertices[j].x - building.vertices[i].x) * (p.y - building.vertices[i].y) / (building.vertices[j].y - building.vertices[i].y) + building.vertices[i].x)) {
            crosses++;
        }
    }
    return crosses % 2 == 1;
}

Point reflect(Point p, Point a, Point b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    double u = ((p.x - a.x) * dx + (p.y - a.y) * dy) / (dx * dx + dy * dy);
    return {2 * a.x + 2 * dx * u - p.x, 2 * a.y + 2 * dy * u - p.y};
}

int main() {
    int N;
    while (std::cin >> N && N != 0) {
        std::vector<Building> buildings(N);
        
        for (int i = 0; i < N; i++) {
            int M;
            std::cin >> M;
            buildings[i].vertices.resize(M);
            for (int j = 0; j < M; j++) {
                std::cin >> buildings[i].vertices[j].x >> buildings[i].vertices[j].y;
            }
        }
        
        Point start, goal;
        std::cin >> start.x >> start.y >> goal.x >> goal.y;
        
        Point line1, line2;
        std::cin >> line1.x >> line1.y >> line2.x >> line2.y;
        
        Point startReflected = reflect(start, line1, line2);
        Point goalReflected = reflect(goal, line1, line2);
        
        // Perform BFS to find the shortest path
        std::queue<Point> q;
        q.push(start);
        
        std::vector<std::vector<double>> distanceTo(N, std::vector<double>(2, -1));
        distanceTo[0][0] = 0;
        
        while (!q.empty()) {
            Point current = q.front();
            q.pop();
            for (int i = 0; i < N; i++) {
                // Check if the current point is inside the building
                if (isInside(current, buildings[i])) {
                    // Check if the reflected point is also inside the same building
                    Point currentReflected = reflect(current, line1, line2);
                    if (!isInside(currentReflected, buildings[i])) continue;
                    
                    // Calculate distance to the goal
                    double distToGoal = distance(current, goal) + distance(currentReflected, goalReflected);
                    
                    if (distanceTo[i][0] == -1 || distToGoal < distanceTo[i][0]) {
                        distanceTo[i][0] = distToGoal;
                        q.push(goal);
                    }
                }
            }
        }
        
        // Output the result
        if (distanceTo[N-1][0] == -1) {
            std::cout << "impossible" << std::endl;
        } else {
            std::cout << std::fixed << std::setprecision(8) << distanceTo[N-1][0] << std::endl;
        }
    }
    
    return 0;
}