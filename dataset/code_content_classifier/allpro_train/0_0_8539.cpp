#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<string>> building(n, vector<string>(m+2, ""));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m+2; j++) {
            cin >> building[i][j];
        }
    }

    // Initialize a vector to store the minimum time to reach each room on the current floor
    vector<int> curr_time(m+2, INT_MAX);
    curr_time[0] = 0;  // Starting at the left stairs

    int total_time = 0;
    for (int i = n-1; i >= 0; i--) {
        // Update the current time to reach the lights on the current floor
        vector<int> next_time(m+2, INT_MAX);
        for (int j = 0; j < m+2; j++) {
            if (building[i][j] == "1") {
                for (int k = 0; k < m+2; k++) {
                    if (curr_time[k] != INT_MAX) {
                        int time = abs(j - k) + min(j, k) + curr_time[k];
                        next_time[j] = min(next_time[j], time);
                    }
                }
            }
        }
        curr_time = next_time;  // Update the current time to reach the lights on the current floor
    }

    // Calculate the total time needed to turn off all the lights
    for (int time : curr_time) {
        total_time = max(total_time, time);
    }

    cout << total_time << endl;

    return 0;
}