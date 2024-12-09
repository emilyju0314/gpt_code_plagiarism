#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1e9;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    int w, h;
    while (cin >> w >> h) {
        if (w == 0 && h == 0) break;
        
        vector<vector<char>> ruins(h, vector<char>(w));
        vector<vector<int>> dist(h, vector<int>(w, INF));
        
        int start_x, start_y;
        int end_x, end_y;
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                cin >> ruins[y][x];
                if (ruins[y][x] == 'S') {
                    start_x = x;
                    start_y = y;
                } else if (ruins[y][x] == 'G') {
                    end_x = x;
                    end_y = y;
                }
            }
        }
        
        queue<pair<int, int>> q;
        q.push({start_x, start_y});
        dist[start_y][start_x] = 0;
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                
                if (new_x >= 0 && new_x < w && new_y >= 0 && new_y < h) {
                    if (ruins[new_y][new_x] != '.' && ruins[new_y][new_x] != 'S') {
                        int seal = ruins[new_y][new_x] - '0';
                        if (dist[new_y][new_x] > dist[y][x] + seal) {
                            dist[new_y][new_x] = dist[y][x] + seal;
                            q.push({new_x, new_y});
                        }
                    } else {
                        if (dist[new_y][new_x] > dist[y][x] + 1) {
                            dist[new_y][new_x] = dist[y][x] + 1;
                            q.push({new_x, new_y});
                        }
                    }
                }
            }
        }
        
        cout << dist[end_y][end_x] << endl;
    }
    
    return 0;
}