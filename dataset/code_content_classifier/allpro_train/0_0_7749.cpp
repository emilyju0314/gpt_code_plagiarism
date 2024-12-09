#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isValid(int r, int c, int n, int m) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> cave(n);
    for(int i = 0; i < n; i++) {
        cin >> cave[i];
    }

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--; c1--; r2--; c2;

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    q.push({r1, c1});
    visited[r1][c1] = true;

    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        if (curr.first == r2 && curr.second == c2) {
            cout << "YES" << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int new_r = curr.first + dr[i];
            int new_c = curr.second + dc[i];

            if (isValid(new_r, new_c, n, m) && cave[new_r][new_c] != 'X' && !visited[new_r][new_c]) {
                visited[new_r][new_c] = true;
                q.push({new_r, new_c});
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}