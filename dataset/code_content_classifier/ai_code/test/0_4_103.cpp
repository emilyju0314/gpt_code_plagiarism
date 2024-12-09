#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<string> board(n);
        for(int i = 0; i < n; i++) {
            cin >> board[i];
        }

        unordered_map<char, pair<int, int>> dir = {{'L', {0, -1}}, {'R', {0, 1}}, {'D', {1, 0}}, {'U', {-1, 0}}};

        int max_steps = 0;
        pair<int, int> start_cell = {1, 1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int cur_steps = 0;
                pair<int, int> cur_cell = {i+1, j+1};
                pair<int, int> next_cell;

                while(true) {
                    next_cell = {cur_cell.first + dir[board[cur_cell.first-1][cur_cell.second-1]].first, cur_cell.second + dir[board[cur_cell.first-1][cur_cell.second-1]].second};

                    if(next_cell.first < 1 || next_cell.first > n || next_cell.second < 1 || next_cell.second > m || next_cell == start_cell) {
                        break;
                    }

                    cur_steps++;
                    cur_cell = next_cell;
                }

                if(cur_steps > max_steps) {
                    max_steps = cur_steps;
                    start_cell = {i+1, j+1};
                }
            }
        }

        cout << start_cell.first << " " << start_cell.second << " " << max_steps << endl;
    }

    return 0;
}