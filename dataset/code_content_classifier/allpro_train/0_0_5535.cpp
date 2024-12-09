#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Point {
    double x, y;
};

struct Building {
    Point bottomLeft;
    Point topRight;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

bool isVisible(Point alice, Point bob, const std::vector<Building>& buildings) {
    for (const Building& building : buildings) {
        if (alice.x >= building.bottomLeft.x && alice.x <= building.topRight.x && alice.y >= building.bottomLeft.y && alice.y <= building.topRight.y) {
            return false;
        }
    }

    return true;
}

int main() {
    int N;
    while (true) {
        std::cin >> N;
        if (N == 0) {
            break;
        }

        std::vector<Building> buildings(N);
        for (int i = 0; i < N; i++) {
            std::cin >> buildings[i].bottomLeft.x >> buildings[i].bottomLeft.y >> buildings[i].topRight.x >> buildings[i].topRight.y;
        }

        Point alice, bob;
        std::cin >> alice.x >> alice.y >> bob.x >> bob.y;

        double min_distance = distance(alice, bob);
        for (int i = 0; i < N; i++) {
            if (isVisible(alice, bob, buildings)) {
                min_distance = std::min(min_distance, distance(alice, bob));
            } else {
                min_distance = std::min(min_distance, distance(alice, Point{buildings[i].bottomLeft.x, buildings[i].bottomLeft.y}) + distance(Point{buildings[i].bottomLeft.x, buildings[i].bottomLeft.y}, bob));
                min_distance = std::min(min_distance, distance(alice, Point{buildings[i].bottomLeft.x, buildings[i].topRight.y}) + distance(Point{buildings[i].bottomLeft.x, buildings[i].topRight.y}, bob));
                min_distance = std::min(min_distance, distance(alice, Point{buildings[i].topRight.x, buildings[i].bottomLeft.y}) + distance(Point{buildings[i].topRight.x, buildings[i].bottomLeft.y}, bob));
                min_distance = std::min(min_distance, distance(alice, Point{buildings[i].topRight.x, buildings[i].topRight.y}) + distance(Point{buildings[i].topRight.x, buildings[i].topRight.y}, bob));
            }
        }

        std::cout << min_distance << std::endl;
    }

    return 0;
}