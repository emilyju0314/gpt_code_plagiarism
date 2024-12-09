#include <iostream>
#include <vector>

bool possibleFold(std::vector<int>& S, int H, int W) {
    std::vector<int> reversed(S.size());
    for (int i = 0; i < S.size(); i++) {
        reversed[S[i]] = i;
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int x = i * W + j;
            int y = reversed[x];

            int targetX = y % W;
            int targetY = y / W;

            if (i != targetY && j != targetX) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<int> S(H * W);
    for (int i = 0; i < H * W; i++) {
        std::cin >> S[i];
    }

    if (possibleFold(S, H, W)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}