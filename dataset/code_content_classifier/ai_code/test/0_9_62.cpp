#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    vector<vector<bool>> matrix(n, vector<bool>(m, false));
    
    set<long long> stairs;

    auto countStairs = [&](int x, int y) {
        long long stairCount = 0;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[i];
                int ny = y + dy[j];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny]) {
                    stairCount |= (1LL << (nx * m + ny));
                }
            }
        }

        return stairCount;
    };

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        
        if (matrix[x][y]) {
            matrix[x][y] = false;
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    stairs.erase(countStairs(nx, ny));
                }
            }
        } else {
            matrix[x][y] = true;
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    stairs.insert(countStairs(nx, ny));
                }
            }
        }
        
        cout << stairs.size() << endl;
    }

    return 0;
}