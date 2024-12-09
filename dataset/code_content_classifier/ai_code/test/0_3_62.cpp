#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<bool>> matrix(n, vector<bool>(m, false));

    auto isInside = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    auto countStaircases = [&]() {
        set<vector<pair<int, int>>> staircases;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] && !visited[i][j]) {
                    vector<pair<int, int>> staircase;
                    int x = i, y = j;
                    while (isInside(x, y) && matrix[x][y]) {
                        staircase.push_back({x, y});
                        visited[x][y] = true;
                        if (isInside(x+1, y) && matrix[x+1][y]) {
                            x++;
                        } else if (isInside(x, y+1) && matrix[x][y+1]) {
                            y++;
                        } else {
                            break;
                        }
                    }
                    staircases.insert(staircase);
                }
            }
        }

        return staircases.size();
    };

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        
        matrix[x][y] = !matrix[x][y];

        cout << countStaircases() << endl;
    }

    return 0;
}