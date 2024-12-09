#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Tank {
    int height;
    int overflow;
};

int main() {
    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        int fx, fy, fq;
        cin >> fx >> fy >> fq;

        vector<vector<Tank>> tanks(h, vector<Tank>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int height;
                cin >> height;
                tanks[i][j].height = height;
            }
        }

        int l;
        cin >> l;
        for (int i = 0; i < l; i++) {
            int tk, xk, yk;
            cin >> tk >> xk >> yk;
            tk = min(tk, fq);

            tanks[fy][fx].overflow = tk;
            while (tk > 0) {
                vector<vector<int>> nextOverflow(h, vector<int>(w));
                for (int y = 0; y < h; y++) {
                    for (int x = 0; x < w; x++) {
                        if (tanks[y][x].height == 0) continue;

                        int count = 0;
                        if (y - 1 >= 0 && tanks[y - 1][x].height > 0) {
                            count++;
                            nextOverflow[y - 1][x] += tanks[y][x].overflow / 4;
                        }
                        if (y + 1 < h && tanks[y + 1][x].height > 0) {
                            count++;
                            nextOverflow[y + 1][x] += tanks[y][x].overflow / 4;
                        }
                        if (x - 1 >= 0 && tanks[y][x - 1].height > 0) {
                            count++;
                            nextOverflow[y][x - 1] += tanks[y][x].overflow / 4;
                        }
                        if (x + 1 < w && tanks[y][x + 1].height > 0) {
                            count++;
                            nextOverflow[y][x + 1] += tanks[y][x].overflow / 4;
                        }
                        int remain = tanks[y][x].overflow - (tanks[y][x].overflow / 4) * count;
                        tanks[y][x].overflow = 0;
                        tanks[y][x].height += remain;
                    }
                }
                tanks = nextOverflow;
                tk--;
            }

            cout << tanks[yk][xk].height / 10 << endl;
        }

    }

    return 0;
}