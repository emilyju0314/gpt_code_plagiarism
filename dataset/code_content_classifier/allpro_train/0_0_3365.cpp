#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Mirror {
    int px, py, qx, qy;
};

int n;
vector<Mirror> mirrors;
int tx, ty, lx, ly;

double dist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

pair<double, double> solve(double angle, double current_x, double current_y, int reflections) {
    if(reflections >= 6)
        return make_pair(1e9, angle);

    double min_dist = 1e9;
    double min_angle = angle;

    int intersect_mirror = -1;
    int next_x, next_y;

    for(int i = 0; i < n; i++) {
        double x1 = mirrors[i].px, y1 = mirrors[i].py;
        double x2 = mirrors[i].qx, y2 = mirrors[i].qy;

        double nx, ny;

        if(abs(x1 - x2) <= 1e-9) {
            double a = tan(angle);
            double b = current_y - a * current_x;
            double y = a * x1 + b;
            nx = 2 * x1 - current_x;
            ny = 2 * y - current_y;
        } else {
            double a = (y2 - y1) / (x2 - x1);
            double b = y1 - a * x1;
            double m = tan(angle);
            double n = current_y - m * current_x;

            double x = (n - b) / (a - m);
            double y = a * x + b;

            nx = 2 * x - current_x;
            ny = 2 * y - current_y;
        }

        double d = dist(nx, ny, tx, ty);
        if(d < min_dist) {
            min_dist = d;
            min_angle = atan2(ny - current_y, nx - current_x);
            next_x = nx;
            next_y = ny;
            intersect_mirror = i;
        }
    }

    if(intersect_mirror == -1)
        return make_pair(min_dist + dist(next_x, next_y, lx, ly), min_angle);

    return solve(min_angle, next_x, next_y, reflections + 1);
}

int main() {
    while(true) {
        cin >> n;
        if(n == 0) break;

        mirrors.resize(n);

        for(int i = 0; i < n; i++) {
            cin >> mirrors[i].px >> mirrors[i].py >> mirrors[i].qx >> mirrors[i].qy;
        }

        cin >> tx >> ty >> lx >> ly;

        double angle = atan2(ty - ly, tx - lx);
        pair<double, double> result = solve(angle, lx, ly, 0);

        cout << fixed;
        cout.precision(15);
        cout << result.first << endl;
    }

    return 0;
}