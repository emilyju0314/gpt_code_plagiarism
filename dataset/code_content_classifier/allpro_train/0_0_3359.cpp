#include <iostream>

int main() {
    int H, W;
    std::cin >> H >> W;

    // 2D array to store the image pixels
    char image[100][100];

    // Input the image pixels
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> image[i][j];
        }
    }

    // Print the extended image
    for (int i = 0; i < 2 * H; i++) {
        for (int j = 0; j < W; j++) {
            std::cout << image[i / 2][j];
        }
        std::cout << std::endl;
    }

    return 0;
}