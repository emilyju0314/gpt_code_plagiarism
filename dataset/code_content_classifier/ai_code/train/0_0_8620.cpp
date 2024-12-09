#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, l, v1, v2, k;
    cin >> n >> l >> v1 >> v2 >> k;

    double time;
    double bus_speed = v2;
    double pupil_speed = v1;
    double distance_remaining = l;
    
    // Calculate time taken for all pupils to walk
    double walk_time = l / v1;

    // Calculate time taken for bus to pick up pupils
    int full_buses = n / k;
    if (n % k != 0) {
        full_buses += 1;
    }
    
    time = walk_time + ((l - v1 * walk_time) / (bus_speed + (k - 1) * (bus_speed - pupil_speed)));

    cout << setprecision(10) << fixed << time << endl;

    return 0;
}