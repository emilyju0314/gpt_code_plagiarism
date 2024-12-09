#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> holidays(N, vector<int>(4));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> holidays[i][j];
        }
    }

    int congestion = 0;
    for (int month = 1; month <= 12; month++) {
        for (int day = 1; day <= 30; day++) {
            int day_congestion = 0;
            for (int i = 0; i < N; i++) {
                if (month == holidays[i][0] && day >= holidays[i][1] && day < holidays[i][1] + holidays[i][2]) {
                    day_congestion = max(day_congestion, holidays[i][3]);
                } else if (day < holidays[i][1]) {
                    day_congestion = max(day_congestion, max(0, holidays[i][3] - day));
                } else if (day >= holidays[i][1] + holidays[i][2]) {
                    day_congestion = max(day_congestion, max(0, holidays[i][3] - 30 + day));
                }
            }
            congestion = max(congestion, day_congestion);
        }
    }

    cout << congestion << endl;

    return 0;
}