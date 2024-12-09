#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool patternMatch(vector<string>& region, int i, int j, vector<string>& pattern, int R, int C) {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (region[i + r][j + c] != pattern[r][c]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> region(H);
    for (int i = 0; i < H; i++) {
        cin >> region[i];
    }

    int R, C;
    cin >> R >> C;

    vector<string> pattern(R);
    for (int i = 0; i < R; i++) {
        cin >> pattern[i];
    }

    for (int i = 0; i <= H - R; i++) {
        for (int j = 0; j <= W - C; j++) {
            if (patternMatch(region, i, j, pattern, R, C)) {
                cout << i << " " << j << endl;
            }
        }
    }

    return 0;
}