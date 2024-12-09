#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> stages(N, vector<int>(N, 0));

    for (int i = 0; i < M; i++) {
        int x, y, s;
        cin >> x >> y >> s;
        stages[x][y] = s;
    }

    int max_stages = 0;

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (stages[i][k] != 0 && stages[k][j] != 0) {
                    stages[i][j] = max(stages[i][j], stages[i][k] + stages[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (stages[0][i] + stages[i][N-1] > max_stages) {
            max_stages = stages[0][i] + stages[i][N-1];
        }
    }

    int additional_stages = max_stages;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (stages[i][j] != 0) {
                additional_stages = max(additional_stages, max_stages - stages[0][i] - stages[j][N-1] + stages[i][j]);
            }
        }
    }

    cout << additional_stages << endl;

    return 0;
}