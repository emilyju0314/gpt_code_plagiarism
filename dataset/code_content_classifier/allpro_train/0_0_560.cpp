#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<vector<int>>> cpus(n, vector<vector<int>>(m, vector<int>(k, 0)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string line;
            cin >> line;
            for (int l = 0; l < k; l++) {
                cpus[i][j][l] = line[l] - '0';
            }
        }
    }

    int critical_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < k; l++) {
                if (cpus[i][j][l] == 1) {
                    if (i > 0 && cpus[i-1][j][l] == 1) {
                        critical_count++;
                    }
                    if (j > 0 && cpus[i][j-1][l] == 1) {
                        critical_count++;
                    }
                    if (l > 0 && cpus[i][j][l-1] == 1) {
                        critical_count++;
                    }
                }
            }
        }
    }

    cout << critical_count << endl;

    return 0;
}