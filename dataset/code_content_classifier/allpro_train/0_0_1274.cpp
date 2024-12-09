#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double PI = 3.141592653589793238462643383279502884;

struct Dancer {
    double x, y, r;
};

double intersectionArea(double r1, double r2, double d) {
    if (r1 + r2 <= d) return 0;
    if (r1 >= r2 + d) return PI * r2 * r2;
    double alpha = 2 * acos((r1*r1 + d*d - r2*r2) / (2*r1*d));
    double beta = 2 * acos((r2*r2 + d*d - r1*r1) / (2*r2*d));
    return 0.5 * (r1*r1*(alpha - sin(alpha)) + r2*r2*(beta - sin(beta)));
}

int main() {
    int n;
    cin >> n;

    vector<Dancer> dancers(n);
    for (int i = 0; i < n; i++) {
        cin >> dancers[i].x >> dancers[i].y >> dancers[i].r;
    }

    double result = 0.0;

    for (int mask = 0; mask < (1 << n); mask++) {
        vector<double> areas;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                areas.push_back(PI * dancers[i].r * dancers[i].r);
            } else {
                areas.push_back(-PI * dancers[i].r * dancers[i].r);
            }
        }
        
        sort(areas.begin(), areas.end());
        
        double sum = 0.0;
        for (int i = 0; i < n; i++) {
            sum += areas[i];
            if (i % 2 == 0) {
                result = max(result, abs(sum));
            }
        }
    }

    cout << fixed << result << endl;

    return 0;
}