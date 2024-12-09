#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> adj_matrix(n, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj_matrix[a-1][b-1] = true;
        adj_matrix[b-1][a-1] = true;
    }

    int max_dominoes = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (adj_matrix[i][j]) {
                max_dominoes++;
            }
        }
    }

    cout << max_dominoes << endl;

    return 0;
}