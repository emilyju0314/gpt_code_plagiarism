#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r, c, n, k;
    cin >> r >> c >> n >> k;

    vector<vector<bool>> grid(r, vector<bool>(c, false));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        grid[x-1][y-1] = true;
    }

    int ans = 0;
    for (int i1 = 0; i1 < r; i1++) {
        for (int j1 = 0; j1 < c; j1++) {
            for (int i2 = i1; i2 < r; i2++) {
                for (int j2 = j1; j2 < c; j2++) {
                    int count = 0;
                    for (int i = i1; i <= i2; i++) {
                        for (int j = j1; j <= j2; j++) {
                            if (grid[i][j]) {
                                count++;
                            }
                        }
                    }
                    if (count >= k) {
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}