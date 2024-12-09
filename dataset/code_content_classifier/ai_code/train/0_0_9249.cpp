#include <iostream>
using namespace std;

int main() {
    int H, W, h, w;
    cin >> H >> W >> h >> w;

    if (H % h == 0 && W % w == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (i % h == 0 && j % w == 0) {
                    cout << -1000000000 << " ";
                } else {
                    cout << 1000000000 << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}