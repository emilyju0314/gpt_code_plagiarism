#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> heights(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> heights[i][j];
        }
    }

    vector<int> max_heights(n + m - 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            max_heights[i + j] = max(max_heights[i + j], heights[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int max_height = max_heights[i + j];
            cout << max_height << " ";
        }
        cout << endl;
    }

    return 0;
}