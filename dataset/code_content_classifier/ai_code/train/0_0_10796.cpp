#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<double> y(n);
    for (int i = 0; i < n; i++) {
        y[i] = r;
        for (int j = 0; j < i; j++) {
            int dx = abs(x[i] - x[j]);
            if (dx <= 2*r) {
                double dy = 2 * sqrt(4*r*r - dx*dx);
                y[i] = max(y[i], y[j] + dy);
            }
        }
    }

    cout << fixed << setprecision(10);
    for (int i = 0; i < n; i++) {
        cout << y[i] << " ";
    }

    return 0;
}