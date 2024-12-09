#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int x, y, time;
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    int W, H;
    cin >> W >> H;

    char maze[H][W];
    int startX, startY, goalX, goalY;
    vector<pair<int, int>> scrolls;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'S') {
                startX = j;
                startY = i;
            } else if (maze[i][j] == 'G') {
                goalX = j;
                goalY = i;
            } else if (maze[i][j] == 'M') {
                scrolls.push_back(make_pair(j, i));
            }
        }
    }

    int total_time = 0;

    for (auto scroll : scrolls) {
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        queue<Node> q;
        q.push({startX, startY, 0});
        
        while (!q.empty()) {
            Node current = q.front();
            q.pop();

            if (current.x == scroll.first && current.y == scroll.second) {
                total_time += current.time;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int newX = current.x + dx[i];
                int newY = current.y + dy[i];

                if (newX >= 0 && newX < W && newY >= 0 && newY < H && maze[newY][newX] != '#' && !visited[newY][newX]) {
                    int new_time = current.time;
                    if (maze[newY][newX] == 'M') {
                        new_time += 3;
                    } else {
                        new_time += 1;
                    }
                    q.push({newX, newY, new_time});
                    visited[newY][newX] = true;
                }
            }
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    queue<Node> q;
    q.push({scrolls.back().first, scrolls.back().second, 0});
    
    while (!q.empty()) {
        Node current = q.front();
        q.pop();

        if (current.x == goalX && current.y == goalY) {
            total_time += current.time;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (newX >= 0 && newX < W && newY >= 0 && newY < H && maze[newY][newX] != '#' && !visited[newY][newX]) {
                int new_time = current.time;
                if (maze[newY][newX] == 'M') {
                    new_time += 3;
                } else {
                    new_time += 1;
                }
                q.push({newX, newY, new_time});
                visited[newY][newX] = true;
            }
        }
    }

    cout << total_time << endl;

    return 0;
}