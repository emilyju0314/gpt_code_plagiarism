#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    vector<int> f(pow(2, n));
    for (int i = 0; i < pow(2, n); i++) {
        cin >> f[i];
    }

    double sum = 0;
    for (int i = 0; i < pow(2, n); i++) {
        sum += f[i];
    }

    for (int i = 0; i < pow(2, n); i++) {
        cout << fixed << setprecision(6) << sum / pow(2, n) << endl;
    }

    for (int i = 0; i < r; i++) {
        int z, g;
        cin >> z >> g;

        sum -= f[z];
        f[z] = g;
        sum += f[z];

        for (int j = 0; j < pow(2, n); j++) {
            cout << fixed << setprecision(6) << sum / pow(2, n) << endl;
        }
    }

    return 0;
}