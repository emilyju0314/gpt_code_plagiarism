#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> mat(n, vector<int>(m));
        vector<int> sorted_indices(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
            sorted_indices[i] = i;
        }

        sort(sorted_indices.begin(), sorted_indices.end(), [&](int a, int b) {
            return mat[a][0] < mat[b][0];
        });

        string colors(n, 'R');
        for (int i = 1; i < n; i++) {
            bool all_same = true;
            for (int j = 0; j < m; j++) {
                if (mat[sorted_indices[i]][j] != mat[sorted_indices[i - 1]][j]) {
                    all_same = false;
                    break;
                }
            }
            if (all_same) {
                cout << "NO" << endl;
                return 0;
            }
        }

        for (int i = 1; i < n; i++) {
            colors[sorted_indices[i]] = (i % 2 == 0) ? 'B' : 'R';
        }

        int k = 0;
        while (k < m && mat[sorted_indices[0]][k] == mat[sorted_indices[0]][0]) {
            k++;
        }

        cout << "YES" << endl;
        cout << colors << " " << k << endl;
    }

    return 0;
}