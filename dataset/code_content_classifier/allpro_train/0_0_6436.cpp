#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Circle {
    int x, y;
};

bool isInsideCircle(int x, int y, const Circle& circle, int t) {
    return (x - circle.x) * (x - circle.x) + (y - circle.y) <= t * t;
}

bool isInsideAnyCircle(int x, int y, const vector<Circle>& circles, int t) {
    for (const Circle& circle : circles) {
        if (isInsideCircle(x, y, circle, t)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<Circle> circles(n);
    for (int i = 0; i < n; i++) {
        cin >> circles[i].x >> circles[i].y;
    }

    double result = -1;
    for (int t = 1; t <= 10000; t++) {
        int numHoles = 0;
        for (int x = -100; x <= 100; x++) {
            for (int y = -100; y <= 100; y++) {
                if (!isInsideAnyCircle(x, y, circles, t) && isInsideAnyCircle(x, y, circles, t - 1)) {
                    numHoles++;
                }
            }
        }
        if (numHoles == 0) {
            result = sqrt(2 * t - 1);
            break;
        }
    }

    cout << fixed;
    cout.precision(6);
    cout << result << endl;

    return 0;
}