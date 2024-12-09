#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, c0, d0;
    cin >> n >> m >> c0 >> d0;

    vector<int> a(m), b(m), c(m), d(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    int maxTugriks = 0;

    // Try all possible combinations of buns with different stuffings and without any stuffing
    for (int mask = 0; mask < (1 << m); mask++) {
        int doughLeft = n;
        int tugriks = 0;

        for (int i = 0; i < m; i++) {
            if ((mask >> i) & 1) {
                int numBuns = min(a[i] / b[i], doughLeft / c[i]);
                tugriks += numBuns * d[i];
                doughLeft -= numBuns * c[i];
            }
        }

        int numBunsWithoutStuffing = min(doughLeft / c0, doughLeft / c0);
        tugriks += numBunsWithoutStuffing * d0;

        maxTugriks = max(maxTugriks, tugriks);
    }

    cout << maxTugriks << endl;

    return 0;
}