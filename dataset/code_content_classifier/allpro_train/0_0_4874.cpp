#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n, l, v1, v2;
    cin >> n >> l >> v1 >> v2;

    vector<int> chocolates(n);
    for(int i = 0; i < n; i++) {
        cin >> chocolates[i];
    }

    vector<double> probabilities(n + 1, 0.0);

    for(int i = 0; i <= n; i++) {
        int pick_up_count = i;
        double time_needed = 0.0;

        for(int j = 0; j < n; j++) {
            double distance = chocolates[j];
            if(pick_up_count > 0) {
                double time_to_reach = distance / (v1 + v2);
                time_needed = max(time_needed, time_to_reach);
            } else {
                double time_to_reach = l - distance / (v2 - v1);
                time_needed = max(time_needed, time_to_reach);
            }
        }

        double total_time = 2 * l / v1;
        probabilities[i] = time_needed / total_time;
    }

    for(int i = 0; i <= n; i++) {
        cout << setprecision(20) << fixed << probabilities[i] << endl;
    }

    return 0;
}