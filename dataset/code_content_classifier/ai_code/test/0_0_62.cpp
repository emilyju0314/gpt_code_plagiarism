#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int n, m, q;

bool is_valid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int count_staircases(const vector<vector<bool>>& grid) {
    int count = 0;
    unordered_set<int> vis;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(grid[i][j]) {
                int hash_val = (i * 1000) + j;
                if(vis.find(hash_val) == vis.end()) {
                    count++;
                    vis.insert(hash_val);

                    int x = i, y = j;
                    while(is_valid(x+1, y) && grid[x+1][y]) x++;
                    if(is_valid(x, y+1) && grid[x][y+1]) y++;

                    while(is_valid(x, y)) {
                        vis.insert((x * 1000) + y);
                        if(is_valid(x, y+1) && grid[x][y+1]) {
                            while(is_valid(x+1, y) && grid[x+1][y]) x++;
                        } else {
                            while(is_valid(x, y+1) && grid[x][y+1]) y++;
                        }
                    }
                }
            }
        }
    }

    return count;
}

int main() {
    cin >> n >> m >> q;

    vector<vector<bool>> grid(n+1, vector<bool>(m+1, false));

    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;

        grid[x][y] = !grid[x][y];

        cout << count_staircases(grid) << endl;
    }

    return 0;
}