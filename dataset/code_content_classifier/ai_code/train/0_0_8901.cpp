#include <iostream>
#include <cmath>

int calculateNumOfCircles(int xA, int yA, int rA, int xB, int yB, int rB) {
    double distanceAB = sqrt(pow(xA - xB, 2) + pow(yA - yB, 2));
    double alpha = asin((rA - rB) / distanceAB);

    int numOfCircles = 1;
    for (int i = 1; i <= 360; i++) {
        double theta = i * 3.14159265358979323846 / 180;  // converting degrees to radians
        double beta = asin(rA * sin(theta) / distanceAB);
        
        if (alpha + beta <= 3.14159265358979323846 / 2) {
            numOfCircles++;
        }
    }

    return numOfCircles;
}

int main() {
    int T;
    std::cin >> T;

    for (int t = 0; t < T; t++) {
        int xA, yA, rA, xB, yB, rB;
        std::cin >> xA >> yA >> rA >> xB >> yB >> rB;

        int result = calculateNumOfCircles(xA, yA, rA, xB, yB, rB);
        std::cout << result << std::endl;
    }

    return 0;
}