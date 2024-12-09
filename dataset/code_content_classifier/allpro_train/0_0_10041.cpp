#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countChains(vector<string>& grid) {
    int chains = 0;
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] != '.' && visited[i][j] == 0) {
                char color = grid[i][j];
                int chainLength = 1;

                vector<pair<int, int>> toVisit = {{i, j}};
                visited[i][j] = 1;

                while (!toVisit.empty()) {
                    pair<int, int> curr = toVisit.back();
                    toVisit.pop_back();

                    int x = curr.first;
                    int y = curr.second;

                    if (x > 0 && grid[x - 1][y] == color && visited[x - 1][y] == 0) {
                        toVisit.push_back({x - 1, y});
                        visited[x - 1][y] = 1;
                        chainLength++;
                    }
                    if (x < grid.size() - 1 && grid[x + 1][y] == color && visited[x + 1][y] == 0) {
                        toVisit.push_back({x + 1, y});
                        visited[x + 1][y] = 1;
                        chainLength++;
                    }
                    if (y > 0 && grid[x][y - 1] == color && visited[x][y - 1] == 0) {
                        toVisit.push_back({x, y - 1});
                        visited[x][y - 1] = 1;
                        chainLength++;
                    }
                    if (y < grid[0].size() - 1 && grid[x][y + 1] == color && visited[x][y + 1] == 0) {
                        toVisit.push_back({x, y + 1});
                        visited[x][y + 1] = 1;
                        chainLength++;
                    }
                }

                if (chainLength >= 4) {
                    chains++;
                }
            }
        }
    }
    return chains;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        vector<string> grid(12);
        for (int i = 0; i < 12; i++) {
            cin >> grid[i];
        }

        int chains = countChains(grid);
        cout << chains << endl;
    }

    return 0;
}
