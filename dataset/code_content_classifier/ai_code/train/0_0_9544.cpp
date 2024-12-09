#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> results(n, vector<int>(n, -1));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        results[u][v] = 1;
        results[v][u] = 0;
    }

    vector<int> team_order(n);
    iota(team_order.begin(), team_order.end(), 0);

    int max_beauty = 0;
    do {
        int beauty = 0;
        vector<int> wins(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int a = team_order[i], b = team_order[j];
                if (results[a][b] == 1) {
                    wins[a]++;
                    beauty++;
                } else if (results[a][b] == 0) {
                    wins[b]++;
                    beauty++;
                }
            }
        }

        if (beauty > max_beauty) {
            max_beauty = beauty;

            vector<vector<int>> remaining_results(n, vector<int>(n, -1));
            for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                    int a = team_order[i], b = team_order[j];
                    if (results[a][b] == -1) {
                        if (wins[a] > wins[b]) {
                            remaining_results[a][b] = 1;
                        } else {
                            remaining_results[b][a] = 1;
                        }
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (remaining_results[i][j] == 1) {
                        cout << "1";
                    } else {
                        cout << "0";
                    }
                }
                cout << endl;
            }
        }
    } while (next_permutation(team_order.begin(), team_order.end()));

    return 0;
}