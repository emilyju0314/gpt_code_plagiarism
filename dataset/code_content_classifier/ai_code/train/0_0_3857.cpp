#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> grid(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    int q;
    cin >> q;

    for (int k = 0; k < q; k++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int count = 0;
        for (int i = r1-1; i < r2; i++) {
            for (int j = c1-1; j < c2; j++) {
                if (j+1 < c2 && grid[i][j] == '.' && grid[i][j+1] == '.') {
                    count++;
                }
                if (i+1 < r2 && grid[i][j] == '.' && grid[i+1][j] == '.') {
                    count++;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}