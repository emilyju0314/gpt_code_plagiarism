#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, l, v1, v2, k;
    cin >> n >> l >> v1 >> v2 >> k;

    // Calculate the time taken for all pupils to reach on foot
    double time_on_foot = (double)l / v1;

    // Calculate the time taken if all pupils take the bus
    double time_on_bus = (double)l / v2;
    double num_round_trips = (double)n / k;
    time_on_bus += num_round_trips - 1; // -1 because they only need to wait at the beginning

    double total_time = max(time_on_foot, time_on_bus);
    cout << fixed << setprecision(10) << total_time << endl;

    return 0;
}