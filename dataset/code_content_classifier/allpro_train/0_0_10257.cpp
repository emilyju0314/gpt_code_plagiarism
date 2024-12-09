#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<char>> table;
vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int maxProfit = 0;
int t;
vector<int> treasures;
vector<vector<int>> dp;

bool insidePolyline(int x, int y, vector<pair<int, int>> polyline) {
    int intersections = 0;
    for (int i = 0; i < polyline.size(); i++) {
        int x1 = polyline[i].first;
        int y1 = polyline[i].second;
        int x2 = polyline[(i + 1) % polyline.size()].first;
        int y2 = polyline[(i + 1) % polyline.size()].second;
        if ((y1 > y) != (y2 > y) && x < (x2 - x1) * (y - y1) / (y2 - y1) + x1) {
            intersections++;
        }
    }
    return intersections % 2 == 1;
}

void dfs(int x, int y, int profit, int moves, vector<pair<int, int>> polyline) {
    if (moves > 0 && x == polyline[0].first && y == polyline[0].second) {
        maxProfit = max(maxProfit, profit);
        return;
    }
    for (pair<int, int> dir : directions) {
        int newX = x + dir.first;
        int newY = y + dir.second;
        if (newX >= 0 && newX < n && newY >= 0 && newY < m && table[newX][newY] != '#' && !insidePolyline(newX, newY, polyline)) {
            int newProfit = profit;
            int newMoves = moves;
            if (table[newX][newY] >= '1' && table[newX][newY] <= '8') {
                newProfit += treasures[table[newX][newY] - '0'];
            }
            if (table[newX][newY] == 'B') {
                continue;
            }
            if (table[newX][newY] == '.' || (newX == polyline[0].first && newY == polyline[0].second)) {
                newMoves++;
            }
            polyline.push_back({newX, newY});
            dfs(newX, newY, newProfit, newMoves, polyline);
            polyline.pop_back();
        }
    }
}

int main() {
    cin >> n >> m;
    table.resize(n, vector<char>(m));
    pair<int, int> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
            if (table[i][j] == 'S') {
                start = {i, j};
                table[i][j] = '.';
            }
        }
    }

    cin >> t;
    treasures.resize(9);
    for (int i = 1; i <= t; i++) {
        cin >> treasures[i];
    }

    dp.resize(n, vector<int>(m, -1));
    vector<pair<int, int>> polyline = {start};
    dfs(start.first, start.second, 0, 0, polyline);

    cout << maxProfit << endl;

    return 0;
}