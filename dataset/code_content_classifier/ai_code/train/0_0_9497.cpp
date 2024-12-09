#include <iostream>
#include <vector>

using namespace std;

struct Star {
    int x, y, s;
};

int main() {
    int n, q, c;
    cin >> n >> q >> c;

    vector<Star> stars(n);
    for (int i = 0; i < n; i++) {
        cin >> stars[i].x >> stars[i].y >> stars[i].s;
    }

    vector<vector<int>> brightness(c+1, vector<int>(101*101, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= c; j++) {
            brightness[j][stars[i].x * 101 + stars[i].y] += (stars[i].s + j) % (c + 1);
        }
    }

    for (int i = 0; i < q; i++) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;

        int ans = 0;
        for (int j = 0; j <= c; j++) {
            int cur_brightness = 0;
            for (int x = x1; x < x2; x++) {
                for (int y = y1; y < y2; y++) {
                    cur_brightness += brightness[j][x * 101 + y];
                }
            }
            ans += (cur_brightness + j) % (c + 1);
        }

        cout << ans << endl;
    }

    return 0;
}