#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Segment {
    double x1, y1, x2, y2;
};

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int N;
    double amax;
    cin >> N >> amax;

    vector<Segment> segments(N);
    for(int i = 0; i < N; i++) {
        cin >> segments[i].x1 >> segments[i].y1 >> segments[i].x2 >> segments[i].y2;
    }

    double time = 0.0;
    double vx = 0.0, vy = 0.0;
    for(int i = 0; i < N; i++) {
        double dist = distance(segments[i].x1, segments[i].y1, segments[i].x2, segments[i].y2);
        double v = sqrt(vx * vx + vy * vy);
        double a = amax;
        
        if(i == 0) {
            time += sqrt(2 * dist / amax);
        } else {
            double t1 = v / a;
            double d1 = 0.5 * a * t1 * t1;
            double d2 = dist - d1;
            double t2 = sqrt(2 * d2 / a);
            time += t1 + t2;
        }

        vx = (segments[i].x2 - segments[i].x1) / dist;
        vy = (segments[i].y2 - segments[i].y1) / dist;
    }

    cout.precision(10);
    cout << fixed << time << endl;

    return 0;
}