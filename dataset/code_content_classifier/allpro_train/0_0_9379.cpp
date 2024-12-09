#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> horizontalEdges(n, vector<int>(m - 1));
    vector<vector<int>> verticalEdges(n - 1, vector<int>(m));

    // Input the number of exhibits on each edge
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m - 1; j++) {
            cin >> horizontalEdges[i][j];
        }
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m; j++) {
            cin >> verticalEdges[i][j];
        }
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, INF)));

    // Base case: the starting vertex has boredness 0
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dp[i][j][0] = 0;
        }
    }

    // Dynamic programming to calculate the minimum possible boredness
    for(int t = 1; t <= k; t++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // Try all possible movements to update the boredness
                for(int di = -1; di <= 1; di++) {
                    for(int dj = -1; dj <= 1; dj++) {
                        if(abs(di) + abs(dj) == 1) {
                            int ni = i + di;
                            int nj = j + dj;
                            if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
                                int wt = (di == 1) ? verticalEdges[ni - 1][j] : 
                                         (di == -1) ? verticalEdges[ni][j] :
                                         (dj == 1) ? horizontalEdges[ni][nj - 1] :
                                         (dj == -1) ? horizontalEdges[ni][nj] : 0;

                                if(dp[ni][nj][t-1] != INF) {
                                    dp[i][j][t] = min(dp[i][j][t], dp[ni][nj][t-1] + wt);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Output the result
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dp[i][j][k] == INF) {
                cout << -1 << " ";
            } else {
                cout << dp[i][j][k] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}