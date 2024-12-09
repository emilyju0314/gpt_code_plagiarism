#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool canCarry(int N, int s, int t, int F, vector<vector<int>>& coefficients, vector<int>& constants, vector<vector<int>>& machines, vector<vector<int>>& capacities) {
    // Implement the function to check if it's possible to carry F liters of cream from s to t per day
}

double minDamage(int N, int s, int t, int F, vector<vector<int>>& coefficients, vector<int>& constants, vector<vector<int>>& machines, vector<vector<int>>& capacities) {
    if (!canCarry(N, s, t, F, coefficients, constants, machines, capacities)) {
        return -1; // If it's not possible, return -1
    }

    // Implement the algorithm to calculate the minimum amount of damage
    
    return 0; // Return the result
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, s, t, F;
        cin >> N >> s >> t >> F;

        vector<vector<int>> coefficients(N, vector<int>(N));
        vector<int> constants(N);
        vector<vector<int>> machines(N, vector<int>());
        vector<vector<int>> capacities(N, vector<int>());

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> coefficients[i][j];
            }
            cin >> constants[i];
        }

        for (int i = 0; i < N; i++) {
            int M;
            cin >> M;
            machines[i].resize(M);
            capacities[i].resize(M);
            for (int j = 0; j < M; j++) {
                cin >> machines[i][j];
                cin >> capacities[i][j];
            }
        }

        double result = minDamage(N, s, t, F, coefficients, constants, machines, capacities);

        if (result == -1) {
            cout << "impossible" << endl;
        } else {
            cout << fixed << result << endl;
        }
    }

    return 0;
}