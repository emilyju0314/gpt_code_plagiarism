#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int bfs(vector<string>& graph, int startVertex, int endVertex) {
    int rows = graph.size();
    int cols = graph[0].size();

    vector<vector<int>> distances(rows, vector<int>(cols, -1));
    queue<pair<int, int>> q;

    int startX, startY, endX, endY;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (graph[i][j] == startVertex) {
                distances[i][j] = 0;
                q.push({i, j});
            } else if (graph[i][j] == endVertex) {
                endX = i;
                endY = j;
            }
        }
    }

    while (!q.empty()) {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        // Check all 4 neighbors
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (abs(i) + abs(j) != 1) continue; // Skip diagonal and center

                int newX = currX + i;
                int newY = currY + j;

                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                    if (distances[newX][newY] == -1 && graph[newX][newY] != '.' && graph[newX][newY] != '-' && graph[newX][newY] != '|') {
                        distances[newX][newY] = distances[currX][currY] + 1;
                        q.push({newX, newY});
                    }
                }
            }
        }
    }

    return distances[endX][endY];
}

int main() {
    int H, W;
    char s, t;
    cin >> H >> W >> s >> t;

    vector<string> graph(H);
    for (int i = 0; i < H; i++) {
        cin >> graph[i];
    }

    int shortestPath = bfs(graph, s, t);
    cout << shortestPath << endl;

    return 0;
}