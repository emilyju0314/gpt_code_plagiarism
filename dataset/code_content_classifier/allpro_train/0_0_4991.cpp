#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool is_valid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool simulate_robot(vector<vector<char>>& maze, string& instructions, vector<int>& mapping, int x, int y, int idx) {
    int n = maze.size();
    int m = maze[0].size();

    if (maze[x][y] == 'E') {
        return true;
    }

    if (idx == instructions.length()) {
        return false;
    }

    char instruction = instructions[idx];
    int direction = mapping[instruction - '0'];

    int new_x = x + directions[direction].first;
    int new_y = y + directions[direction].second;

    if (is_valid(new_x, new_y, n, m) && maze[new_x][new_y] != '#') {
        return simulate_robot(maze, instructions, mapping, new_x, new_y, idx + 1);
    }

    return false;
}

int count_mappings(vector<vector<char>>& maze, string& instructions) {
    int result = 0;
    vector<int> mapping = {0, 1, 2, 3};

    do {
        if (simulate_robot(maze, instructions, mapping, 0, 0, 0)) {
            result++;
        }
    } while (next_permutation(mapping.begin(), mapping.end()));

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> maze(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    string instructions;
    cin >> instructions;

    int result = count_mappings(maze, instructions);
    cout << result << endl;

    return 0;
}