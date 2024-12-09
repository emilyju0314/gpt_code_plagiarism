#include <iostream>
#include <vector>

using namespace std;

// Function to check if a given day's weather forecast satisfies the conditions
bool canSatisfyWeather(int day, vector<vector<int>>& schedule) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (schedule[day][i * 4 + j] == 1) { // If it's a market or festival day
                count++;
            }
        }
    }
    return count < 9; // There should be no more than 8 market or festival days
}

int main() {
    int N;
    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }

        vector<vector<int>> schedule(N, vector<int>(16));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 16; j++) {
                cin >> schedule[i][j];
            }
        }

        bool canSatisfy = true;

        // First-day weather
        if (!canSatisfyWeather(0, schedule)) {
            canSatisfy = false;
        }

        // Subsequent days weather
        for (int i = 1; i < N; i++) {
            if (!canSatisfyWeather(i, schedule)) {
                if (i < N - 1) { // Check if moving the cloud to the other direction would help
                    if (!canSatisfyWeather(i + 1, schedule)) {
                        canSatisfy = false;
                        break;
                    }
                } else {
                    canSatisfy = false;
                    break;
                }
                i++; // Skip the next day since it wasn't possible to satisfy the weather condition
            }
        }

        if (canSatisfy) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}