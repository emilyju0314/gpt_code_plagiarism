#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> grid(H);
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }

    int max_area = 0;
    for (int i = 0; i < H; i++) {
        for (int j = i + 1; j < H; j++) {
            int num_black = 0;
            for (int k = 0; k < W; k++) {
                if (grid[i][k] == '#' && grid[j][k] == '#') {
                    num_black++;
                }
            }
            max_area = max(max_area, num_black * (j - i + 1));
        }
    }

    cout << max_area << endl;

    return 0;
}