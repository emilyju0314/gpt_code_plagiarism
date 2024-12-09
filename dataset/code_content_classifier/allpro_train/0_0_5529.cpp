#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int N, R;
    cin >> N >> R;

    vector<int> x(N), w(N), h(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> w[i] >> h[i];
    }

    double left = -100, right = 100;
    for (int i = 0; i < N; i++) {
        double r = R;
        for (int j = 0; j < i; j++) {
            if (x[j] + w[j] < x[i]) continue;
            double y = h[j];
            r = max(r, (x[i] - left) / (x[i] - x[j]) * y);
        }
        for (int j = i - 1; j >= 0; j--) {
            if (x[j] > x[i] + w[i]) continue;
            double y = h[j];
            r = max(r, (right - (x[i] + w[i])) / (x[j] - x[i] - w[i]) * y);
        }
        right = min(right, x[i]);
        left = max(left, x[i] + w[i]);
    }

    cout << fixed << setprecision(8) << (right + left) / 2 << endl;

    return 0;
}