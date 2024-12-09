#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    double low = 0, high = 1000;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        high = max(high, (double)a[i]);
    }

    for (int i = 0; i < 100; i++) {
        double mid = (low + high) / 2.0;
        double sum = 0;
        
        for (int j = 0; j < n; j++) {
            if (a[j] > mid) {
                sum += (a[j] - mid) * (1 - k / 100.0);
            } else {
                sum -= (mid - a[j]);
            }
        }

        if (sum >= 0) {
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << fixed << setprecision(9) << low << endl;

    return 0;
}