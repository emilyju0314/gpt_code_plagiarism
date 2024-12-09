#include <iostream>

int main() {
    while (true) {
        int H, W;
        std::cin >> H >> W;

        if (H == 0 && W == 0) {
            break;
        }

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if ((i + j) % 2 == 0) {
                    std::cout << '#';
                } else {
                    std::cout << '.';
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}