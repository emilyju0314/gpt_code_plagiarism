#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int x, y, scientists;
};

int main() {
    int n, t;
    cin >> n >> t;

    vector<vector<char>> scientists(n, vector<char>(n));
    vector<vector<char>> capsules(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> scientists[i][j];
        }
    }

    string empty;
    getline(cin, empty);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> capsules[i][j];
        }
    }

    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(n, vector<bool>(t+1, false));

    queue<Node> q;
    q.push({0, 0, scientists[0][0]-'0'});
    visited[0][0][0] = true;

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    int ans = 0;

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        if (capsules[curr.x][curr.y] != '0' && curr.scientists <= capsules[curr.x][curr.y]-'0') {
            ans = max(ans, curr.scientists);
        }

        if (curr.scientists == 0) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int new_x = curr.x + dx[i];
            int new_y = curr.y + dy[i];

            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && scientists[new_x][new_y] != 'Z' && !visited[new_x][new_y][t-1]) {
                q.push({new_x, new_y, curr.scientists-1});
                visited[new_x][new_y] = true;
            }
        }
    }

    cout << ans << endl;

    return 0;
}