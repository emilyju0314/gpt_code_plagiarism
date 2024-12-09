#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int R, C, a_i, a_j, b_i, b_j;
    cin >> R >> C >> a_i >> a_j >> b_i >> b_j;

    vector<vector<int>> dist(R, vector<int>(C, INT_MAX));
    vector<vector<int>> paths(R, vector<int>(C, 0));

    dist[a_i][a_j] = 0;
    paths[a_i][a_j] = 1;

    for (int k = 0; k < R*C; k++) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (i + 1 < R && dist[i][j] + 1 < dist[i + 1][j]) {
                    dist[i + 1][j] = dist[i][j] + 1;
                    paths[i + 1][j] = paths[i][j] % MOD;
                }
                if (i - 1 >= 0 && dist[i][j] + 1 < dist[i - 1][j]) {
                    dist[i - 1][j] = dist[i][j] + 1;
                    paths[i - 1][j] = paths[i][j] % MOD;
                }
                if (j + 1 < C && dist[i][j] + 1 < dist[i][j + 1]) {
                    dist[i][j + 1] = dist[i][j] + 1;
                    paths[i][j + 1] = paths[i][j] % MOD;
                }
                if (j - 1 >= 0 && dist[i][j] + 1 < dist[i][j - 1]) {
                    dist[i][j - 1] = dist[i][j] + 1;
                    paths[i][j - 1] = paths[i][j] % MOD;
                }
            }
        }
    }

    cout << dist[b_i][b_j] << " " << paths[b_i][b_j] << endl;

    return 0;
}