#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, T;
    cin >> n >> T;

    vector<int> a(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    double low = 0, high = 1e8;
    for (int i = 0; i < 100; i++) {
        double mid = (low + high) / 2;

        double sum = 0, sum_t = 0;
        for (int j = 0; j < n; j++) {
            if (t[j] > mid) {
                sum += (t[j] - mid) * a[j];
                sum_t += a[j];
            }
        }

        if (sum / sum_t >= T) {
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << fixed;
    cout.precision(9);
    cout << min(T, low) << endl;

    return 0;
}