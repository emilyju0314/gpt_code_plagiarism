#include <iostream>

using namespace std;

int main() {
    int W, H;
    cin >> W >> H;

    int building[H][W];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> building[i][j];
        }
    }

    int wallLength = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (building[i][j] == 1) {
                // Check for surrounding buildings and add wall length accordingly
                if (i == 0 || building[i-1][j] == 0) wallLength++;
                if (i == H-1 || building[i+1][j] == 0) wallLength++;
                if (i % 2 == 0) {
                    if (j == 0 || building[i][j-1] == 0) wallLength++;
                    if (j == W-1 || building[i][j+1] == 0) wallLength++;
                    if (i > 0 && j > 0 && building[i-1][j-1] == 0) wallLength++;
                    if (i > 0 && building[i-1][j] == 0) wallLength++;
                    if (i < H-1 && building[i+1][j-1] == 0) wallLength++;
                    if (i < H-1 && building[i+1][j] == 0) wallLength++;
                } else {
                    if (j == 0 || building[i][j-1] == 0) wallLength++;
                    if (j == W-1 || building[i][j+1] == 0) wallLength++;
                    if (i > 0 && building[i-1][j] == 0) wallLength++;
                    if (i > 0 && j < W-1 && building[i-1][j+1] == 0) wallLength++;
                    if (i < H-1 && building[i+1][j] == 0) wallLength++;
                    if (i < H-1 && j < W-1 && building[i+1][j+1] == 0) wallLength++;
                }
            }
        }
    }

    cout << wallLength * 2 << endl;

    return 0;
}