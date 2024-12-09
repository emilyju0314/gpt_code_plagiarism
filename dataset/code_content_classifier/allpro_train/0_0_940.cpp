#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

const int INF = 1e9;

int main() {
    int W, H;
    
    while (true) {
        cin >> W >> H;
        if (W == 0 && H == 0) {
            break;
        }
        
        int f, m, o;
        cin >> f >> m >> o;
        
        vector<vector<int>> formation(H, vector<int>(W));
        vector<vector<int>> oxygens(H, vector<int>(W, 0));
        
        int startY = -1;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> formation[i][j];
                if (formation[i][j] > 0) {
                    oxygens[i][j] = formation[i][j];
                }
                if (oxygens[i][j] > 0 && startY == -1) {
                    startY = i;
                }
            }
        }
        
        int dp[50][10][10];  // dp[i][j][k] represents the minimum cost to reach cell with coordinates (j, k) with i oxygen remaining
        
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    dp[i][j][k] = INF;
                }
            }
        }
        
        dp[o][startY][0] = 0;
        priority_queue<tuple<int, int, int, int>> pq;  // cost, oxygen, y, x
        pq.push(make_tuple(0, o, startY, 0));
        
        while (!pq.empty()) {
            int cost, oxygen, y, x;
            tie(cost, oxygen, y, x) = pq.top();
            pq.pop();
            
            if (y == H - 1) {
                cout << cost << endl;
                break;
            }
            
            for (int dx = -1; dx <= 1; dx++) {
                int nx = x + dx;
                if (nx < 0 || nx >= W) continue;
                int ny = y + 1;
                if (oxygen <= 0) break;
                
                if (formation[ny][nx] > 0) {
                    int next_oxygen = min(m, oxygen + oxygens[ny][nx]);
                    int next_cost = cost + 1;
                    if (next_cost < dp[next_oxygen][ny][nx]) {
                        dp[next_oxygen][ny][nx] = next_cost;
                        pq.push(make_tuple(-next_cost, next_oxygen, ny, nx));
                    }
                } else {
                    int next_oxygen = oxygen - 1;
                    int next_cost = cost - formation[ny][nx];
                    if (next_cost >= f) continue;
                    if (next_cost < dp[next_oxygen][ny][nx]) {
                        dp[next_oxygen][ny][nx] = next_cost;
                        pq.push(make_tuple(-next_cost, next_oxygen, ny, nx));
                    }
                }
            }
        }
        
        if (dp[o][H-1][0] == INF) {
            cout << "NA" << endl;
        }
    }
    
    return 0;
}