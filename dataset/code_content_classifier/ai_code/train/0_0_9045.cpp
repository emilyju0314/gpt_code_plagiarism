#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> garden(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> garden[i][j];
        }
    }

    int a, b;
    cin >> a >> b;

    int min_trees = a * b;
    for (int i = 0; i <= n - a; i++) {
        for (int j = 0; j <= m - b; j++) {
            int trees_chopped = 0;
            for (int x = i; x < i + a; x++) {
                for (int y = j; y < j + b; y++) {
                    trees_chopped += garden[x][y];
                }
            }
            min_trees = min(min_trees, trees_chopped);
        }
    }

    cout << min_trees << endl;

    return 0;
}