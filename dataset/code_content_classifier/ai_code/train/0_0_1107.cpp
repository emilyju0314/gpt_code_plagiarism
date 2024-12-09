#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> maze(H);
    for(int i = 0; i < H; i++) {
        cin >> maze[i];
    }

    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int maxMoves = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(maze[i][j] == '.') { // starting from every road square
                queue<pair<int, int>> q;
                vector<vector<int>> dist(H, vector<int>(W, -1));
                q.push({i, j});
                dist[i][j] = 0;

                while(!q.empty()) {
                    pair<int, int> current = q.front();
                    q.pop();

                    for(auto dir : directions) {
                        int new_i = current.first + dir.first;
                        int new_j = current.second + dir.second;

                        if(new_i >= 0 && new_i < H && new_j >= 0 && new_j < W && maze[new_i][new_j] == '.' && dist[new_i][new_j] == -1) {
                            q.push({new_i, new_j});
                            dist[new_i][new_j] = dist[current.first][current.second] + 1;
                            maxMoves = max(maxMoves, dist[new_i][new_j]);
                        }
                    }
                }
            }
        }
    }

    cout << maxMoves << endl;

    return 0;
}