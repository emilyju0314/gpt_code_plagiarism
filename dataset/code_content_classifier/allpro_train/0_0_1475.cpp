#include <iostream>

using namespace std;

int main() {
    int H, W, X, Y;
    cin >> H >> W >> X >> Y;

    if ((H * W) % 2 == 1 && (X + Y) % 2 == 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}