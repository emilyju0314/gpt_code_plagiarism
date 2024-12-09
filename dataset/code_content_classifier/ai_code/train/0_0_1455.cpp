#include <iostream>
#include <string>

using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;

    int s_r, s_c;
    cin >> s_r >> s_c;

    string S, T;
    cin >> S >> T;

    bool pieceOnGrid = true;

    int r = s_r, c = s_c;
    for (int i = 0; i < N; i++) {
        char directionTakahashi = S[i];
        char directionAoki = T[i];

        if (directionTakahashi == 'L') {
            c--;
        } else if (directionTakahashi == 'R') {
            c++;
        } else if (directionTakahashi == 'U') {
            r--;
        } else if (directionTakahashi == 'D') {
            r++;
        }

        // Check if the piece is still on the grid
        if (r < 1 || r > H || c < 1 || c > W) {
            pieceOnGrid = false;
            break;
        }

        if (directionAoki == 'L') {
            c++;
        } else if (directionAoki == 'R') {
            c--;
        } else if (directionAoki == 'U') {
            r++;
        } else if (directionAoki == 'D') {
            r--;
        }

        if (r < 1 || r > H || c < 1 || c > W) {
            break;
        }
    }

    if (pieceOnGrid) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}