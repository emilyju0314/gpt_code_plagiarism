#include <iostream>
#include <vector>
#include <cmath>

struct Property {
    int id;
    std::vector<std::pair<double, double>> points;
};

double polygonArea(std::vector<std::pair<double, double>> points) {
    double area = 0.0;
    int j = points.size() - 1;

    for (int i = 0; i < points.size(); i++) {
        area += (points[j].first + points[i].first) * (points[j].second - points[i].second);
        j = i;
    }

    return std::abs(area) / 2.0;
}

bool circleIntersectsPolygon(double x, double y, double r, std::vector<std::pair<double, double>> points) {
    // Check if any of the polygon edges intersect with the circle
    // Implement this function based on geometry concepts

    return false;
}

int main() {
    double width, height;
    int n;
    std::cin >> width >> height >> n;

    std::vector<Property> properties(n);
    for (int i = 0; i < n; i++) {
        int v;
        std::cin >> v;
        properties[i].id = i;

        for (int j = 0; j < v; j++) {
            double x, y;
            std::cin >> x >> y;
            properties[i].points.push_back({x, y});
        }
    }

    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        double x, y, r;
        std::cin >> x >> y >> r;

        double totalArea = 0.0;
        int count = 0;
        std::vector<int> acquiredProperties;

        for (int j = 0; j < n; j++) {
            if (circleIntersectsPolygon(x, y, r, properties[j].points)) {
                totalArea += polygonArea(properties[j].points);
                count++;
                acquiredProperties.push_back(properties[j].id);
            }
        }

        // Output total area, count, and acquired property IDs
        std::cout << totalArea << " " << count << " ";
        for (int id : acquiredProperties) {
            std::cout << id << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}