#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> attitudes(n, vector<int>(3));
    for(int i = 0; i < n; i++) {
        cin >> attitudes[i][0] >> attitudes[i][1] >> attitudes[i][2];
    }

    int max_attitude = 0;
    vector<string> result;

    for(int i = 0; i < pow(2, n); i++) {
        vector<int> attitude_sum(3, 0);
        vector<int> companions;
        int temp_i = i;

        for(int j = 0; j < n; j++) {
            if(temp_i % 2 == 1) {
                companions.push_back(j);
                for(int k = 0; k < 3; k++) {
                    attitude_sum[k] += attitudes[j][k];
                }
            }
            temp_i /= 2;
        }

        if(attitude_sum[0] + attitude_sum[1] + attitude_sum[2] == 0) {
            if(companions.size() == 2) {
                int current_attitude = abs(attitude_sum[0]) + abs(attitude_sum[1]) + abs(attitude_sum[2]);
                if(current_attitude > max_attitude) {
                    max_attitude = current_attitude;
                    result.clear();
                    result.push_back((companions[0] == 0 ? "LM" : (companions[0] == 1 ? "MW" : "LW")));
                    result.push_back((companions[1] == 0 ? "LM" : (companions[1] == 1 ? "MW" : "LW")));
                }
            }
        }
    }

    if(result.empty()) {
        cout << "Impossible" << endl;
    } else {
        for(int i = 0; i < n; i++) {
            cout << result[i % 2] << endl;
        }
    }

    return 0;
}