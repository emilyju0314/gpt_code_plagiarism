#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> grid(H);
    for(int i = 0; i < H; i++) {
        cin >> grid[i];
    }

    int answer = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(grid[i][j] == '.') {
                int count = 1;

                for(int k = 1; j + k < W && grid[i][j + k] == '.'; k++) {
                    count++;
                }
                for(int k = 1; j - k >= 0 && grid[i][j - k] == '.'; k++) {
                    count++;
                }
                for(int k = 1; i + k < H && grid[i + k][j] == '.'; k++) {
                    count++;
                }
                for(int k = 1; i - k >= 0 && grid[i - k][j] == '.'; k++) {
                    count++;
                }

                answer = max(answer, count);
            }
        }
    }

    cout << answer << endl;

    return 0;
}