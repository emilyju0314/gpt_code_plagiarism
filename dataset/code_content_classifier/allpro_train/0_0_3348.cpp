#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int hh, mm, H, D, C, N;
    cin >> hh >> mm;
    cin >> H >> D >> C >> N;

    int start_time = hh * 60 + mm; // Convert time to minutes
    int time_needed = max(0, 20*60 - start_time); // Calculate time needed to reach store

    double cost_no_discount = ceil((H + time_needed*D) / double(N)) * C; // Calculate cost without discount
    double cost_with_discount = ceil(H/double(N)) * C; // Calculate cost with discount

    cout << fixed << setprecision(4) << min(cost_no_discount, 0.8 * cost_with_discount) << endl;

    return 0;
}