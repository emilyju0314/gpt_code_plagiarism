#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> campus(H, vector<char>(W));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> campus[i][j];
        }
    }

    int maxDistance = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (campus[i][j] == 'B') {
                for (int k = 0; k < H; k++) {
                    for (int l = 0; l < W; l++) {
                        if (campus[k][l] == 'B') {
                            int distance = abs(i - k) + abs(j - l);
                            maxDistance = max(maxDistance, distance);
                        }
                    }
                }
            }
        }
    }

    cout << maxDistance << endl;

    return 0;
}