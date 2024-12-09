#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> colors(N, vector<int>(4));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> colors[i][j];
        }
    }

    set<vector<int>> cubes;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            for (int k = 0; k < N; k++) {
                if (i == k || j == k) continue;
                for (int l = 0; l < N; l++) {
                    if (i == l || j == l || k == l) continue;
                    for (int m = 0; m < N; m++) {
                        if (i == m || j == m || k == m || l == m) continue;
                        for (int n = 0; n < N; n++) {
                            if (i == n || j == n || k == n || l == n || m == n) continue;

                            vector<int> cube = {colors[i][0], colors[j][1], colors[k][2], colors[l][3], colors[m][2], colors[n][0]};
                            cubes.insert(cube);
                        }
                    }
                }
            }
        }
    }

    cout << cubes.size() << endl;

    return 0;
}