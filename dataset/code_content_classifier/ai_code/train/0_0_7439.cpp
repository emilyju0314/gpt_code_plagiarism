#include <iostream>
#include <vector>
#include <bitset>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> stamps;
    vector<string> colors(4);

    for (int i = 0; i < N; i++) {
        int H, W;
        cin >> H >> W;
        stamps.push_back({H, W});
    }

    for (int i = 0; i < 4; i++) {
        cin >> colors[i];
    }

    int ans = INT_MAX;
    for (int mask = 0; mask < (1 << N); mask++) {
        int requiredStamps = 0;
        vector<vector<bool>> visited(4, vector<bool>(4, false));
        
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                int H = stamps[i].first;
                int W = stamps[i].second;

                for (int r = 0; r + H <= 4; r++) {
                    for (int c = 0; c + W <= 4; c++) {
                        bool canCover = true;
                        for (int x = r; x < r + H; x++) {
                            for (int y = c; y < c + W; y++) {
                                if (visited[x][y] || colors[x][y] != colors[r][c]) {
                                    canCover = false;
                                    break;
                                }
                            }
                            if (!canCover) break;
                        }

                        if (canCover) {
                            requiredStamps++;
                            for (int x = r; x < r + H; x++) {
                                for (int y = c; y < c + W; y++) {
                                    visited[x][y] = true;
                                }
                            }
                        }
                    }
                }
            }
        }

        bool complete = true;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (!visited[i][j]) {
                    complete = false;
                    break;
                }
            }
            if (!complete) break;
        }

        if (complete) {
            ans = min(ans, requiredStamps);
        }
    }

    cout << ans << endl;

    return 0;
}