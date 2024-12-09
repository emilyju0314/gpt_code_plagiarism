#include<iostream>
#include<vector>

int main() {
    int N, C;
    std::cin >> N >> C;

    std::vector<int> cakes(C);
    for(int i = 0; i < C; i++) {
        std::cin >> cakes[i];
    }

    int min_cakes = 100;
    for(int i = 0; i < C; i++) {
        if(cakes[i] < min_cakes) {
            min_cakes = cakes[i];
        }
    }

    int rest = 0;
    for(int i = 0; i < C; i++) {
        rest += cakes[i] - min_cakes;
    }

    rest += min_cakes;  // the host gets one piece

    std::cout << rest << std::endl;

    return 0;
}