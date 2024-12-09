#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int building[4][3][10] = {0};

    for(int i = 0; i < n; i++) {
        int b, f, r, v;
        std::cin >> b >> f >> r >> v;

        building[b-1][f-1][r-1] += v;
    }

    for(int b = 0; b < 4; b++) {
        for(int f = 0; f < 3; f++) {
            for(int r = 0; r < 10; r++) {
                std::cout << building[b][f][r] << " ";
            }
            std::cout << std::endl;
        }

        std::cout << "####################" << std::endl;
    }

    return 0;
}