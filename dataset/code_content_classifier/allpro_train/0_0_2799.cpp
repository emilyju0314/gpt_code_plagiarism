#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, q, a, b;
    cin >> n >> q >> a >> b;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<double> y(n);
    for (int i = 1; i < n; i++) {
        int diff = min(b, (x[i] - x[i - 1]) / a);
        y[i] = y[i - 1] + diff * a;
    }

    double sum = 0;
    for (int i = 1; i < n; i++) {
        sum += pow(x[i] - y[i], 2);
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << y[i];
    }
    cout << endl;

    cout << fixed;
    cout.precision(6);
    cout << sum << endl;

    return 0;
}