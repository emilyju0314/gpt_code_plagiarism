#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to check if the rat can cross the wall
bool canCross(int xs, int ys, int xt, int yt, int xi, int yi, int ri) {
    double distance = sqrt(pow(xi - xs, 2) + pow(yi - ys, 2));
    return distance - ri > sqrt(pow(xt - xs, 2) + pow(yt - ys, 2));
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        int xs, ys, xt, yt;
        cin >> xs >> ys >> xt >> yt;

        int minWalls = 0;
        for (int i = 0; i < n; i++) {
            int xi, yi, ri;
            cin >> xi >> yi >> ri;

            if (!canCross(xs, ys, xt, yt, xi, yi, ri)) {
                minWalls++;
            }
        }

        cout << minWalls << endl;
    }

    return 0;
}