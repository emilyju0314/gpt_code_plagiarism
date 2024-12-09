#include<iostream>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    int D[H][W];

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> D[i][j];
        }
    }

    int s_i = 0, s_j = 0, t_i = 0, t_j = 0;
    bool found = false;

    for (int i = 1; i < H - 1; i++) {
        for (int j = 1; j < W - 1; j++) {
            if (D[i][j] == 3) {
                s_i = i;
                s_j = j;
                while (D[i][j] == 3) j++;
                t_i = i;
                t_j = j;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    cout << s_i << " " << s_j << " " << t_i << " " << t_j << endl;

    return 0;
}