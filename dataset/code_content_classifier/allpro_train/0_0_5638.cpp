#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> building_positions(n);
    for (int i = 0; i < n; i++) {
        cin >> building_positions[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int xi;
        cin >> xi;

        int building_index = 0;
        while (building_index < n && building_positions[building_index] <= xi) {
            building_index++;
        }

        double terminal_angle;
        // Calculate terminal angle α_x based on positions of buildings and xi
        if (building_index == 0) {
            terminal_angle = atan2(1, xi - building_positions[0]);
        } else if (building_index == n) {
            terminal_angle = atan2(1, xi - building_positions[n - 1]);
        } else {
            double angle_left = atan2(1, xi - building_positions[building_index - 1]);
            double angle_right = atan2(1, building_positions[building_index] - xi);
            terminal_angle = min(angle_left, angle_right);
        }

        cout << fixed << terminal_angle << endl;
    }

    return 0;
}