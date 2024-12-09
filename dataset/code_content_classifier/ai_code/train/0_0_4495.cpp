#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

int main() {
    int N;
    while (true) {
        cin >> N;
        if (N == 0) break;

        double xs, ys, zs, xt, yt, zt;
        cin >> xs >> ys >> zs >> xt >> yt >> zt;

        vector<double> energy(N, 0.0);
        for (int i = 0; i < N; i++) {
            double x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

            double d1 = distance(xs, ys, zs, x1, y1, z1) + distance(x1, y1, z1, x2, y2, z2) + distance(x2, y2, z2, xt, yt, zt);
            double d2 = distance(xs, ys, zs, x2, y2, z2) + distance(x2, y2, z2, x1, y1, z1) + distance(x1, y1, z1, xt, yt, zt);

            energy[i] = min(d1, d2);
        }

        double result = *min_element(energy.begin(), energy.end());
        cout << fixed;
        cout << setprecision(3);
        cout << result << endl;
    }

    return 0;
}