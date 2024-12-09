#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, X;
    cin >> N >> M >> X;

    vector<int> C(N);
    vector<vector<int>> A(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        cin >> C[i];
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    int min_cost = -1;
    for (int mask = 0; mask < (1 << N); mask++) {
        vector<int> skills(M, 0);
        int cost = 0;

        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                cost += C[i];
                for (int j = 0; j < M; j++) {
                    skills[j] += A[i][j];
                }
            }
        }

        bool check = true;
        for (int j = 0; j < M; j++) {
            if (skills[j] < X) {
                check = false;
                break;
            }
        }

        if (check) {
            if (min_cost == -1) {
                min_cost = cost;
            } else {
                min_cost = min(min_cost, cost);
            }
        }
    }

    cout << min_cost << endl;

    return 0;
}