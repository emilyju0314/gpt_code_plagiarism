#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, V;
    cin >> N >> V;

    double totalLength = 0.0;
    double prevX, prevY;
    cin >> prevX >> prevY;

    for (int i = 1; i < N; i++) {
        double x, y;
        cin >> x >> y;

        double slope = (y - prevY) / (x - prevX);
        double angle = atan(slope);

        if (angle < 0) {
            angle *= -1;
        }

        double jumpHeight = V * sin(angle) / 9.8;
        double distanceX = x - prevX;
        double distanceY = y - prevY;

        totalLength += sqrt(distanceX * distanceX + distanceY * distanceY) + 2 * jumpHeight;

        prevX = x;
        prevY = y;
    }

    cout.precision(10);
    cout << totalLength << endl;

    return 0;
}