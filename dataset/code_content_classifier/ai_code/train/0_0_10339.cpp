#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Target {
    int x, y, t;
    double p;
};

int main() {
    int n;
    cin >> n;

    vector<Target> targets(n);
    for(int i = 0; i < n; i++) {
        cin >> targets[i].x >> targets[i].y >> targets[i].t >> targets[i].p;
    }

    vector<double> dp(1 << n, 0.0);
    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++) {
            if((mask & (1 << i)) == 0) {
                double prob = max(0.0, (double(targets[i].t) - sqrt(targets[i].x * targets[i].x + targets[i].y * targets[i].y)) / double(targets[i].t));
                dp[mask | (1 << i)] = max(dp[mask | (1 << i)], dp[mask] + prob * targets[i].p);
            }
        }
    }

    cout << fixed << setprecision(10) << dp[(1 << n) - 1] << endl;

    return 0;
}