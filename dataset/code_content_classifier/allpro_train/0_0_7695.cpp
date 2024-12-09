#include <iostream>
#include <vector>

int main() {
    int W, H;
    std::cin >> W >> H;

    std::vector<int> a(W);
    for (int i = 0; i < W; i++) {
        std::cin >> a[i];
    }

    std::vector<int> b(H);
    for (int j = 0; j < H; j++) {
        std::cin >> b[j];
    }

    int totalTreasure = 0;
    for (int i = 0; i < W; i++) {
        totalTreasure += a[i];
    }
    for (int j = 0; j < H; j++) {
        int count = 0;
        for (int i = 0; i < W; i++) {
            if (count < b[j]) {
                count += a[i];
            } else if (count == b[j]) {
                break;
            } else {
                std::cout << "0" << std::endl;
                return 0;
            }
        }
        if (count != b[j]) {
            std::cout << "0" << std::endl;
            return 0;
        }
    }

    if (totalTreasure == b[H - 1]) {
        std::cout << "1" << std::endl;
    } else {
        std::cout << "0" << std::endl;
    }

    return 0;
}