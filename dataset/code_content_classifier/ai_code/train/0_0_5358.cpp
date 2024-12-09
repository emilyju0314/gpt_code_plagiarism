#include <iostream>
#include <vector>

int main() {
    int N, W, H, S, T;
    
    while (true) {
        std::cin >> N;
        if (N == 0) break;
        
        std::cin >> W >> H >> S >> T;
        
        std::vector<std::vector<int>> field(W, std::vector<int>(H, 0));
        
        for (int i = 0; i < N; i++) {
            int x, y;
            std::cin >> x >> y;
            field[x-1][y-1] = 1;
        }
        
        int maxCount = 0;
        
        for (int i = 0; i <= W - S; i++) {
            for (int j = 0; j <= H - T; j++) {
                int count = 0;
                for (int k = i; k < i + S; k++) {
                    for (int l = j; l < j + T; l++) {
                        count += field[k][l];
                    }
                }
                maxCount = std::max(maxCount, count);
            }
        }
        
        std::cout << maxCount << std::endl;
    }
    
    return 0;
}