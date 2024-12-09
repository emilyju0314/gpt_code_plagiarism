#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> takeoff_coef(n);
    vector<int> landing_coef(n);

    for (int i = 0; i < n; i++) {
        cin >> takeoff_coef[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> landing_coef[i];
    }

    double initial_mass = m;
    double fuel_mass = 0.0;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            fuel_mass += initial_mass / takeoff_coef[i];
            initial_mass += fuel_mass;
        } else {
            fuel_mass += initial_mass / takeoff_coef[i];
            initial_mass += fuel_mass;
            fuel_mass += initial_mass / landing_coef[i];
            initial_mass -= fuel_mass;
        }
    }

    if (initial_mass >= 0) {
        cout << fixed;
        cout.precision(10);
        cout << fuel_mass << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}