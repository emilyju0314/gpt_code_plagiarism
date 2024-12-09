#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x, y, z;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

bool isSimilarTriangle(double a, double b, double c, double x, double y, double z) {
    double ratio1 = a / x;
    double ratio2 = b / y;
    double ratio3 = c / z;
    if (abs(ratio1 - ratio2) <= 0.0001 && abs(ratio1 - ratio3) <= 0.0001) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int num_datasets;
    std::cin >> num_datasets;

    for (int i = 0; i < num_datasets; i++) {
        double a, b, c;
        std::cin >> a >> b >> c;

        int num_candidates;
        std::cin >> num_candidates;

        std::vector<Point> candidates(num_candidates);
        for (int j = 0; j < num_candidates; j++) {
            std::cin >> candidates[j].x >> candidates[j].y >> candidates[j].z;
        }

        std::vector<int> result;
        for (int j = 0; j < num_candidates; j++) {
            for (int k = j + 1; k < num_candidates; k++) {
                for (int l = k + 1; l < num_candidates; l++) {
                    double side1 = distance(candidates[j], candidates[k]);
                    double side2 = distance(candidates[j], candidates[l]);
                    double side3 = distance(candidates[k], candidates[l]);

                    if (isSimilarTriangle(a, b, c, side1, side2, side3)) {
                        result = {j+1, k+1, l+1};
                        break;
                    }
                }
                if (!result.empty()) {
                    break;
                }
            }
            if (!result.empty()) {
                break;
            }
        }

        for (int j = 0; j < result.size(); j++) {
            std::cout << result[j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}