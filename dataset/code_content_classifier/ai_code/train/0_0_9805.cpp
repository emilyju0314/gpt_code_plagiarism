#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> forest(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> forest[i][j];
        }
    }

    int T = 0;
    vector<vector<char>> result(n, vector<char>(m, '.'));
    vector<vector<bool>> burnt(n, vector<bool>(m, false));

    // Perform a simulation to find the maximum time T and the set of trees initially set on fire
    bool fire_spread = true;
    while (fire_spread) {
        fire_spread = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (forest[i][j] == 'X') {
                    bool change_flag = false;
                    for (int dx = -1; dx <= 1; dx++) {
                        for (int dy = -1; dy <= 1; dy++) {
                            int ni = i + dx;
                            int nj = j + dy;
                            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                                if (!burnt[ni][nj] && forest[ni][nj] == '.') {
                                    change_flag = true;
                                    result[ni][nj] = 'X';
                                    burnt[ni][nj] = true;
                                    fire_spread = true;
                                }
                            }
                        }
                    }
                    if (change_flag) {
                        fire_spread = true;
                        burnt[i][j] = true;
                    }
                }
            }
        }
        if (fire_spread) {
            T++;
            forest = result;
        }
    }

    cout << T << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j];
        }
        cout << endl;
    }

    return 0;
}