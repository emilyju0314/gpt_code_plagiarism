#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int r, x, y, n;
    cin >> r >> x >> y >> n;

    vector<int> percentages(n);
    for(int i = 0; i < n; i++) {
        cin >> percentages[i];
    }

    double total_area = M_PI * r * r;

    // Calculate areas of each item when center coordinates are at (0,0)
    vector<double> areas_original(n);
    for(int i = 0; i < n; i++) {
        areas_original[i] = total_area * percentages[i] / 100.0;
    }

    // Calculate areas of each item when center coordinates are at (x,y)
    vector<double> areas_new(n);
    for(int i = 0; i < n; i++) {
        double angle = 2 * M_PI * (percentages[i] / 200.0);
        double new_r = sqrt((x * x) + (y * y));
        areas_new[i] = 0.5 * angle * new_r * new_r;
    }

    // Calculate percentage change in area for each item
    vector<int> changes(n);
    for(int i = 0; i < n; i++) {
        double change = ((areas_new[i] - areas_original[i]) / areas_original[i]) * 100.0;
        changes[i] = floor(change);
    }

    // Output the percentage change in area for each item
    for(int i = 0; i < n; i++) {
        cout << changes[i] << " ";
    }
    cout << endl;

    return 0;
}