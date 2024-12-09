#include <iostream>
#include <vector>
#include <cmath>

struct Gem {
    int x, y, r, m;
};

int main() {
    int N;
    while (std::cin >> N && N != 0) {
        std::vector<Gem> gems(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> gems[i].x >> gems[i].y >> gems[i].r >> gems[i].m;
        }
        
        int maxAdsorbed = 0;
        for (int i = 0; i < N; ++i) {
            int adsorbed = 0;
            for (int j = 0; j < N; ++j) {
                if (j == i) continue;
                int dx = gems[j].x - gems[i].x;
                int dy = gems[j].y - gems[i].y;
                double distance = std::sqrt(dx*dx + dy*dy);
                if (distance <= gems[i].m && distance <= gems[j].m) {
                    if ((gems[j].m - distance) >= gems[i].r) {
                        adsorbed++;
                    }
                }
            }
            maxAdsorbed = std::max(maxAdsorbed, adsorbed);
        }
        
        std::cout << maxAdsorbed << std::endl;
    }
    
    return 0;
}