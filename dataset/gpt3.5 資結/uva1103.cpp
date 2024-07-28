#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

#define WALL '#'
#define EMPTY '.'

int h, w;
vector<string> grid;
vector<vector<bool>> visited;
vector<vector<int>> tag;
map<int, int> pixels;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void dfs(int x, int y, int t) {
    if (x < 0 || x >= h || y < 0 || y >= w || visited[x][y] || grid[x][y] == WALL) {
        return;
    }

    visited[x][y] = true;
    tag[x][y] = t;
    pixels[t]++;

    for (int i = 0; i < 4; i++) {
        dfs(x + dx[i], y + dy[i], t);
    }
}

void flood_fill() {
    visited.assign(h, vector<bool>(w, false));
    tag.assign(h, vector<int>(w, 0));
    int tag_count = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!visited[i][j] && grid[i][j] == EMPTY) {
                dfs(i, j, tag_count++);
            }
        }
    }
}

void solve(int case_num) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (tag[i][j] == 0) {
                pixels[tag[i][j]]++;
            }
        }
    }

    map<int, char> mapping;
    mapping[0] = 'W';
    mapping[1] = 'A';
    mapping[2] = 'K';
    mapping[3] = 'J';

    string result = "";
    for (auto p : pixels) {
        result += mapping[p.first];
        result += ":";
        result += to_string(p.second);
        result += " ";
    }

    cout << "Case " << case_num << ": " << result << "\n";
}

int main() {
    int case_num = 1;
    while (cin >> h >> w && h != 0 && w != 0) {
        grid.clear();
        pixels.clear();

        for (int i = 0; i < h; i++) {
            string row;
            cin >> row;
            grid.push_back(row);
        }

        flood_fill();
        solve(case_num++);
    }

    return 0;
}