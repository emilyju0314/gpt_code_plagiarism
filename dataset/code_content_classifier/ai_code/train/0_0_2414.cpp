#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> purple(H, vector<char>(W));
    vector<vector<char>> red(H, vector<char>(W, '.'));
    vector<vector<char>> blue(H, vector<char>(W, '.'));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> purple[i][j];
            if (purple[i][j] == '#') {
                red[i][j] = '#';
                blue[i][j] = '#';
            }
        }
    }

    // Fill in the gaps in red cells
    for (int i = 0; i < H; i++) {
        bool flag = false;
        for (int j = 0; j < W; j++) {
            if (red[i][j] == '#') {
                flag = true;
            }
            if (flag) {
                red[i][j] = '#';
            }
        }
        flag = false;
        for (int j = W - 1; j >= 0; j--) {
            if (red[i][j] == '#') {
                flag = true;
            }
            if (flag) {
                red[i][j] = '#';
            }
        }
    }

    // Fill in the gaps in blue cells
    for (int j = 0; j < W; j++) {
        bool flag = false;
        for (int i = 0; i < H; i++) {
            if (blue[i][j] == '#') {
                flag = true;
            }
            if (flag) {
                blue[i][j] = '#';
            }
        }
        flag = false;
        for (int i = H - 1; i >= 0; i--) {
            if (blue[i][j] == '#') {
                flag = true;
            }
            if (flag) {
                blue[i][j] = '#';
            }
        }
    }

    // Output the red cells
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << red[i][j];
        }
        cout << endl;
    }
    cout << endl;

    // Output the blue cells
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << blue[i][j];
        }
        cout << endl;
    }

    return 0;
}