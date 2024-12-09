#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> grid(H);

    for(int i = 0; i < H; i++) {
        cin >> grid[i];
    }

    int ans = 0;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(grid[i][j] == '.') {
                int black = 0;
                int white = 0;

                for(int k = j + 1; k < W; k++) {
                    if(grid[i][k] == '#') black++;
                    else white++;

                    if(grid[i][j] == grid[i][k]) continue;

                    ans += black * white;
                }

                black = 0;
                white = 0;

                for(int k = i + 1; k < H; k++) {
                    if(grid[k][j] == '#') black++;
                    else white++;

                    if(grid[i][j] == grid[k][j]) continue;

                    ans += black * white;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}