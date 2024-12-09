#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> forest(n, vector<int>(m, -1));
    queue<pair<int, int>> burning_trees;

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        burning_trees.push({x, y});
        forest[x][y] = 0;
    }

    while (!burning_trees.empty()) {
        int x = burning_trees.front().first;
        int y = burning_trees.front().second;
        burning_trees.pop();

        if (x > 0 && forest[x - 1][y] == -1) {
            forest[x - 1][y] = forest[x][y] + 1;
            burning_trees.push({x - 1, y});
        }
        if (x < n - 1 && forest[x + 1][y] == -1) {
            forest[x + 1][y] = forest[x][y] + 1;
            burning_trees.push({x + 1, y});
        }
        if (y > 0 && forest[x][y - 1] == -1) {
            forest[x][y - 1] = forest[x][y] + 1;
            burning_trees.push({x, y - 1});
        }
        if (y < m - 1 && forest[x][y + 1] == -1) {
            forest[x][y + 1] = forest[x][y] + 1;
            burning_trees.push({x, y + 1});
        }
    }

    int max_time = 0;
    pair<int, int> last_burned_tree;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (forest[i][j] > max_time) {
                max_time = forest[i][j];
                last_burned_tree = {i + 1, j + 1};
            }
        }
    }

    cout << last_burned_tree.first << " " << last_burned_tree.second << endl;

    return 0;
}