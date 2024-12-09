#include <iostream>
#include <vector>

using namespace std;

int X, Y;
vector<vector<char>> store;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<bool>> visited;
int maxDiscount = 0;

void dfs(int x, int y, vector<vector<pair<int, int>>> timeSales, int discount) {
    visited[x][y] = true;
    maxDiscount = max(maxDiscount, discount);

    for (auto d : dir) {
        int newX = x + d.first;
        int newY = y + d.second;

        if (newX >= 0 && newX < Y && newY >= 0 && newY < X && !visited[newX][newY] && store[newX][newY] != '.') {
            for (auto ts : timeSales[store[newX][newY] - '0']) {
                if (ts.first <= discount && ts.second >= discount) {
                    dfs(newX, newY, timeSales, discount + ts.first);
                }
            }
        }
    }

    visited[x][y] = false;
}

int main() {
    while (true) {
        cin >> X >> Y;
        if (X == 0 && Y == 0) break;

        store = vector<vector<char>>(Y, vector<char>(X));
        visited = vector<vector<bool>>(Y, vector<bool>(X, false));
        pair<int, int> startPos;
        vector<vector<pair<int, int>>> timeSales(10);

        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                cin >> store[i][j];
                if (store[i][j] == 'P') {
                    startPos = {i, j};
                }
            }
        }

        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int g, d, s, e;
            cin >> g >> d >> s >> e;
            timeSales[g].push_back({d, s, e});
        }

        maxDiscount = 0;
        dfs(startPos.first, startPos.second, timeSales, 0);
        cout << maxDiscount << endl;
    }

    return 0;
}