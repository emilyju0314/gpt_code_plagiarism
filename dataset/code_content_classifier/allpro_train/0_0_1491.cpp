#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arrays(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arrays[i][j];
        }
    }

    int max_min = 0, idx_i = 0, idx_j = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int min_val = INT_MAX;
            for (int k = 0; k < m; k++) {
                min_val = min(min_val, max(arrays[i][k], arrays[j][k]));
            }
            if (min_val > max_min) {
                max_min = min_val;
                idx_i = i+1;
                idx_j = j+1;
            }
        }
    }

    cout << idx_i << " " << idx_j << endl;

    return 0;
}