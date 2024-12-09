#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    double max_distance = 0;

    for (int mask = 0; mask < (1 << N); mask++) {
        double X = 0, Y = 0;
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                X += x[i];
                Y += y[i];
            }
        }
        double distance = sqrt(X * X + Y * Y);
        max_distance = max(max_distance, distance);
    }

    cout << fixed;
    cout.precision(12);
    cout << max_distance << endl;

    return 0;
}