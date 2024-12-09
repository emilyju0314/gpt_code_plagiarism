#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double stopToppling(vector<Point> chain, Point start, double toppleVelocity, Point you, double yourVelocity) {
    double time = 0;
    double minTime = distance(start, you) / yourVelocity;

    for (int i = 0; i < chain.size() - 1; i++) {
        Point p1 = chain[i];
        Point p2 = chain[i + 1];
        double chainLength = distance(p1, p2);
        double chainTime = chainLength / toppleVelocity;

        double fromStart = distance(start, p1);
        double fromYou = distance(you, p1);

        if (fromStart > fromYou) {
            time = max(fromStart / yourVelocity, fromYou / yourVelocity);
        } else {
            time = (fromYou + fromStart) / yourVelocity;
        }

        time += chainTime;
        minTime = min(time, minTime);
    }

    return minTime;
}

int main() {
    int N;
    cin >> N;

    vector<Point> chain(N);
    for (int i = 0; i < N; i++) {
        cin >> chain[i].x >> chain[i].y;
    }

    Point start, you;
    double toppleVelocity, yourVelocity;

    cin >> start.x >> start.y >> toppleVelocity;
    cin >> you.x >> you.y >> yourVelocity;

    double minTime = stopToppling(chain, start, toppleVelocity, you, yourVelocity);

    cout << minTime << endl;

    return 0;
}