#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W, K;
    cin >> H >> W >> K;

    vector<vector<char>> cake(H, vector<char>(W));
    vector<vector<int>> piece(H, vector<int>(W));

    int current_piece = 1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> cake[i][j];
            if (cake[i][j] == '#') {
                piece[i][j] = current_piece;
                current_piece = (current_piece % K) + 1;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << piece[i][j];
            if (j < W - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}