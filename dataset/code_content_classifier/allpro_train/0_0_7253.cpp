#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int H, W, D;
    cin >> H >> W >> D;

    vector<vector<int>> grid(H, vector<int>(W));
    map<int, pair<int, int>> location;
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
            location[grid[i][j]] = make_pair(i, j);
        }
    }

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int L, R;
        cin >> L >> R;

        pair<int, int> start = location[L];
        pair<int, int> end = location[R];

        int num_moves = abs(end.first - start.first) + abs(end.second - start.second);
        int starting_val = grid[start.first][start.second];
        int step = D;

        int total_moves = 0;
        for (int i = starting_val + D; i <= R; i += D) {
            pair<int, int> next_location = location[i];
            total_moves += abs(next_location.first - start.first) + abs(next_location.second - start.second);
            start = next_location;
        }

        cout << total_moves << endl;
    }

    return 0;
}