#include <iostream>
#include <vector>

using namespace std;

int main() {
    int W, H;
    cin >> W >> H;

    vector<vector<int>> squares(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> squares[i][j];
        }
    }

    bool canAchieve = true;
    int numBlack = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if ((i + j) % 2 != squares[i][j]) {
                canAchieve = false;
                break;
            }
            if (squares[i][j] == 1) {
                numBlack++;
            }
        }
        if (!canAchieve) {
            break;
        }
    }

    if (canAchieve && numBlack == W*H/2) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}