#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int posts[4][4];
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            std::cin >> posts[i][j];
        }
    }

    for(int i = 0; i < 4; i++) {
        int cost1 = std::max(posts[i][0], posts[i][1]);
        int cost2 = std::max(posts[i][2], posts[i][3]);

        if(cost1 + cost2 <= n) {
            std::cout << i+1 << " " << cost1 << " " << n - cost1 << std::endl;
            return 0;
        }
    }

    std::cout << -1 << std::endl;

    return 0;
}