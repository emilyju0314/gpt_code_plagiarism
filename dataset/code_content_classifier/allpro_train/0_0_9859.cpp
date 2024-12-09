#include <iostream>
#include <string>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    char image[H][W];

    // Input the image
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> image[i][j];
        }
    }

    // Print the image with a border
    cout << string(W + 2, '#') << endl;
    for (int i = 0; i < H; i++) {
        cout << "#" << image[i] << "#" << endl;
    }
    cout << string(W + 2, '#') << endl;

    return 0;
}