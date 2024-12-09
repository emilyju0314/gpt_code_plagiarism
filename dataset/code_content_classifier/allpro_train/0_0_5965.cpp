#include <iostream>
#include <vector>

using namespace std;

int main() {
    int W, H, N;
    cin >> W >> H >> N;

    vector<vector<bool>> walls(W+1, vector<bool>(H+1, false));

    for (int i = 0; i < N; i++) {
        int sxi, syi, dxi, dyi;
        cin >> sxi >> syi >> dxi >> dyi;
        for (int x = min(sxi, dxi); x <= max(sxi, dxi); x++) {
            for (int y = min(syi, dyi); y <= max(syi, dyi); y++) {
                walls[x][y] = true;
            }
        }
    }

    int ix, iy, ox, oy;
    cin >> ix >> iy >> ox >> oy;

    vector<vector<int>> dist(W+1, vector<int>(H+1, 1000));
    dist[ix][iy] = 0;

    for (int i = 0; i <= W; i++) {
        for (int j = 0; j <= H; j++) {
            if (walls[i][j]) continue;
            if (i > 0 && !walls[i-1][j]) {
                dist[i-1][j] = min(dist[i-1][j], dist[i][j] + 1);
            }
            if (j > 0 && !walls[i][j-1]) {
                dist[i][j-1] = min(dist[i][j-1], dist[i][j] + 1);
            }
        }
    }

    int min_steps = dist[ox][oy];
    int max_increase = 0;

    for (int i = 0; i <= W; i++) {
        for (int j = 0; j <= H; j++) {
            if (walls[i][j] || (i > 0 && walls[i-1][j]) || (j > 0 && walls[i][j-1])) continue;
            int new_dist = min(dist[ox][oy], min(dist[i][j] + 1 + abs(i-ox) + abs(j-oy), dist[i][j] + 1 + abs(i-ox) + abs(j-oy)));
            max_increase = max(max_increase, new_dist - min_steps);
        }
    }

    cout << max_increase << endl;

    return 0;
}