#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Ball {
    double x, v, m;
};

int main() {
    int n, t;
    cin >> n >> t;

    vector<Ball> balls(n);
    for (int i = 0; i < n; i++) {
        cin >> balls[i].x >> balls[i].v >> balls[i].m;
    }

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (balls[j].x < balls[j + 1].x) {
                double u1 = (balls[j].v * (balls[j].m - balls[j + 1].m) + 2 * balls[j + 1].m * balls[j + 1].v) / (balls[j].m + balls[j + 1].m);
                double u2 = (balls[j + 1].v * (balls[j + 1].m - balls[j].m) + 2 * balls[j].m * balls[j].v) / (balls[j].m + balls[j + 1].m);
                balls[j].v = u1;
                balls[j + 1].v = u2;
            }
        }
        for (int j = 0; j < n; j++) {
            balls[j].x += balls[j].v;
        }
    }

    cout << fixed << setprecision(9);
    for (int i = 0; i < n; i++) {
        cout << balls[i].x << endl;
    }

    return 0;
}