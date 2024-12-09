#include <iostream>
#include <vector>

bool canMakeGoodAmidakuji(int N, std::vector<std::vector<int>>& amidakuji) {
    std::vector<int> currentLines = {0, 1, 2};

    for (int i = 0; i < N; i++) {
        std::vector<int> newLines;
        
        for (int j = 0; j < amidakuji[i][0]; j++) {
            if (amidakuji[i][j + 1] == 0) {
                std::swap(currentLines[j], currentLines[j + 1]);
            }
        }

        if (currentLines[0] == 0 && currentLines[2] == 0) {
            return true;
        }
    }

    return false;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> amidakuji(N, std::vector<int>());

    for (int i = 0; i < N; i++) {
        int w;
        std::cin >> w;

        amidakuji[i].push_back(w);

        for (int j = 0; j < w; j++) {
            int a;
            std::cin >> a;
            amidakuji[i].push_back(a);
        }
    }

    if (canMakeGoodAmidakuji(N, amidakuji)) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    return 0;
}