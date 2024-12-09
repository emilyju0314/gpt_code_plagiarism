#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int h, w, n, r;
int start_x, start_y;
vector<string> map;
vector<pair<char, int>> treasures;
int max_money = 0;

void dfs(int x, int y, int money, int cost) {
    if (money > max_money) {
        max_money = money;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= h || ny < 0 || ny >= w || map[nx][ny] == '#' || map[nx][ny] == '*' || map[nx][ny] == '@') {
            continue;
        }

        int new_money = money;
        int new_cost = cost;

        if (map[nx][ny] >= '0' && map[nx][ny] <= 'Z') {
            for (auto& treasure : treasures) {
                if (treasure.first == map[nx][ny]) {
                    new_money += treasure.second;
                    break;
                }
            }
        } else if (map[nx][ny] == '*') {
            new_cost += r;
        }

        if (new_cost <= new_money) {
            char temp = map[nx][ny];
            map[nx][ny] = '@';
            dfs(nx, ny, new_money, new_cost);
            map[nx][ny] = temp;
        }
    }
}

int main() {
    cin >> h >> w >> n >> r;

    map = vector<string>(h);
    
    for (int i = 0; i < h; i++) {
        cin >> map[i];
        for (int j = 0; j < w; j++) {
            if (map[i][j] == '@') {
                start_x = i;
                start_y = j;
            }
        }
    }

    treasures = vector<pair<char, int>>(n);
    for (int i = 0; i < n; i++) {
        cin >> treasures[i].first >> treasures[i].second;
    }

    dfs(start_x, start_y, 0, 0);

    cout << max_money << endl;

    return 0;
}