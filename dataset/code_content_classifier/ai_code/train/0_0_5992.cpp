#include <iostream>
#include <vector>
#include <cmath>

struct Property {
    int id;
    int points;
    std::vector<std::pair<double, double>> coordinates;
};

double calculateArea(const Property& property) {
    double area = 0.0;
    for (int i = 0; i < property.points; i++) {
        int j = (i + 1) % property.points;
        area += (property.coordinates[i].first * property.coordinates[j].second);
        area -= (property.coordinates[i].second * property.coordinates[j].first);
    }
    area = abs(area) / 2.0;
    return area;
}

bool isIntersecting(double x, double y, double r, const Property& property) {
    double cx = x;
    double cy = y;
    for (int i = 0; i < property.points; i++) {
        double px = property.coordinates[i].first;
        double py = property.coordinates[i].second;
        double distance = sqrt((cx - px) * (cx - px) + (cy - py) * (cy - py));
        if (distance <= r) {
            return true;
        }
    }
    return false;
}

int main() {
    double width, height;
    int n;
    std::cin >> width >> height >> n;

    std::vector<Property> properties(n);
    for (int i = 0; i < n; i++) {
        std::cin >> properties[i].points;
        properties[i].id = i;
        for (int j = 0; j < properties[i].points; j++) {
            double x, y;
            std::cin >> x >> y;
            properties[i].coordinates.push_back({x, y});
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

        for (const Property& property : properties) {
            if (isIntersecting(x, y, r, property)) {
                totalArea += calculateArea(property);
                count++;
                acquiredProperties.push_back(property.id);
            }
        }

        std::cout << totalArea << " " << count << " ";
        for (int id : acquiredProperties) {
            std::cout << id << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}