#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    double fuel_mass = m;
    double total_fuel = fuel_mass;
    for (int i = 1; i < n; i++) {
        if (a[i] == 1 || b[i] == 1) {
            cout << -1 << endl;
            return 0;
        }
        fuel_mass = fuel_mass / (1.0 - 1.0 / a[i]) + b[i];
        total_fuel += fuel_mass;
    }

    cout << fixed << setprecision(10) << total_fuel << endl;

    return 0;
}