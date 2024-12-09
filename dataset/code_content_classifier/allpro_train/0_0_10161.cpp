#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

struct Trench {
    int x1, y1, x2, y2;
};

bool isInsideTrench(int x, int y, const Trench& trench) {
    return x >= std::min(trench.x1, trench.x2) && x <= std::max(trench.x1, trench.x2)
            && y >= std::min(trench.y1, trench.y2) && y <= std::max(trench.y1, trench.y2);
}

double distance(int x1, int y1, int x2, int y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

double minTimeToReach(int a, int b, int Ax, int Ay, int Bx, int By, const std::vector<Trench>& trenches) {
    double minTime = std::numeric_limits<double>::infinity();

    for (const auto& trench : trenches) {
        double distStartATrench = distance(Ax, Ay, trench.x1, trench.y1);
        double distEndATrench = distance(Ax, Ay, trench.x2, trench.y2);
        double distStartBTrench = distance(Bx, By, trench.x1, trench.y1);
        double distEndBTrench = distance(Bx, By, trench.x2, trench.y2);
        
        // Check if Vasya can move from point A to the trench
        double timeToStart = std::max(distStartATrench - a, 0.0);
        double totalTime = distStartATrench + a + b + distEndBTrench;
        
        // Check if Vasya can move from trench to point B
        if (timeToStart + distStartBTrench + a + b + distEndBTrench < totalTime) {
            totalTime = timeToStart + distStartBTrench + a + b + distEndBTrench;
        }
        
        minTime = std::min(minTime, totalTime);
    }

    return minTime < std::numeric_limits<double>::infinity() ? minTime : -1.0;
}

int main() {
    int a, b;
    std::cin >> a >> b;

    int Ax, Ay, Bx, By;
    std::cin >> Ax >> Ay >> Bx >> By;

    int nTrenches;
    std::cin >> nTrenches;

    std::vector<Trench> trenches(nTrenches);
    for (int i = 0; i < nTrenches; ++i) {
        std::cin >> trenches[i].x1 >> trenches[i].y1 >> trenches[i].x2 >> trenches[i].y2;
    }

    double minTime = minTimeToReach(a, b, Ax, Ay, Bx, By, trenches);
    std::cout << std::fixed << minTime << std::setprecision(10) << std::endl;

    return 0;
}