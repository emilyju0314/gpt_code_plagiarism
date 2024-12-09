#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<vector<int>> monitor(n, vector<int>(m, 0));
    vector<vector<int>> brokenPixels(q, vector<int>(3));

    for(int i = 0; i < q; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        x--; y--;
        brokenPixels[i][0] = x;
        brokenPixels[i][1] = y;
        brokenPixels[i][2] = t;
        monitor[x][y] = t;
    }

    int minMoment = -1;
    for(int i = 0; i < q; i++) {
        int x = brokenPixels[i][0];
        int y = brokenPixels[i][1];
        int t = brokenPixels[i][2];

        int minX = max(0, x - k + 1);
        int minY = max(0, y - k + 1);
        int maxX = min(n - k, x);
        int maxY = min(m - k, y);

        for(int j = 0; j <= maxX - minX; j++) {
            for(int l = 0; l <= maxY - minY; l++) {
                bool isBrokenSquare = true;
                for(int p = 0; p < k; p++) {
                    for(int q = 0; q < k; q++) {
                        if(monitor[minX+j+p][minY+l+q] < t) {
                            isBrokenSquare = false;
                            break;
                        }
                    }
                    if(!isBrokenSquare) {
                        break;
                    }
                }
                if(isBrokenSquare) {
                    if(minMoment == -1) {
                        minMoment = t;
                    } else {
                        minMoment = min(minMoment, t);
                    }
                }
            }
        }
    }

    cout << minMoment << endl;

    return 0;
}