#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Node {
    int x, y, cost;
    bool bombActivated;

    Node(int _x, int _y, int _cost, bool _bombActivated) : x(_x), y(_y), cost(_cost), bombActivated(_bombActivated) {}

    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

int main() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;

    vector<vector<char>> stage(H, vector<char>(W));
    int start_x, start_y, exit_x, exit_y;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> stage[i][j];
            if (stage[i][j] == 's') {
                start_x = i;
                start_y = j;
            } else if (stage[i][j] == 'g') {
                exit_x = i;
                exit_y = j;
            }
        }
    }

    vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(2, INF)));
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    pq.push(Node(start_x, start_y, 0, false));
    dist[start_x][start_y][0] = 0;

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.x == exit_x && current.y == exit_y) {
            cout << current.cost << endl;
            return 0;
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                int newCost = current.cost + A;
                int bombActivated = current.bombActivated;

                if (stage[nx][ny] == '.' || stage[nx][ny] == 'g' || (stage[nx][ny] == '*' && !current.bombActivated)) {
                    if (stage[nx][ny] == '*') {
                        newCost += B;
                        bombActivated = true;
                    }

                    if (newCost < dist[nx][ny][bombActivated]) {
                        dist[nx][ny][bombActivated] = newCost;
                        pq.push(Node(nx, ny, newCost, bombActivated));
                    }
                }
            }
        }
    }

    cout << "INF" << endl;

    return 0;
}