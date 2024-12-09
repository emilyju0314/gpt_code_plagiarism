#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int a, v, l, d, w;
    double acceleration, maxSpeed, roadLength, signDistance, signLimit, time;

    std::cin >> a >> v;
    std::cin >> l >> d >> w;

    acceleration = a;
    maxSpeed = v;
    roadLength = l;
    signDistance = d;
    signLimit = w;

    double timeToReachSign = sqrt(2 * signDistance / acceleration);
    double timeToReachBercouver = roadLength / maxSpeed;

    if (maxSpeed >= signLimit) {
        time = timeToReachBercouver;
    } else {
        double timeToReachMaxSpeed = maxSpeed / acceleration;
        if (timeToReachSign + timeToReachMaxSpeed <= timeToReachBercouver) {
            double distanceAfterSign = roadLength - signDistance;
            time = timeToReachSign + distanceAfterSign / maxSpeed;
        } else {
            time = timeToReachBercouver;
        }
    }

    std::cout << std::fixed << std::setprecision(12) << time << std::endl;

    return 0;
}