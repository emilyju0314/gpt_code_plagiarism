#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        int w, h;
        std::cin >> w >> h;
        
        int k;
        std::cin >> k;
        std::vector<int> horizontal1(k);
        for(int i = 0; i < k; i++) {
            std::cin >> horizontal1[i];
        }

        std::cin >> k;
        std::vector<int> horizontal2(k);
        for(int i = 0; i < k; i++) {
            std::cin >> horizontal2[i];
        }

        std::cin >> k;
        std::vector<int> vertical1(k);
        for(int i = 0; i < k; i++) {
            std::cin >> vertical1[i];
        }

        std::cin >> k;
        std::vector<int> vertical2(k);
        for(int i = 0; i < k; i++) {
            std::cin >> vertical2[i];
        }

        int max_horizontal = 0;
        for(int i = 1; i < horizontal1.size(); i++) {
            int dist = horizontal1[i] - horizontal1[i-1];
            max_horizontal = std::max(max_horizontal, dist);
        }

        int max_vertical = 0;
        for(int i = 1; i < vertical1.size(); i++) {
            int dist = vertical1[i] - vertical1[i-1];
            max_vertical = std::max(max_vertical, dist);
        }

        int result = std::max(max_horizontal, w - horizontal1.back()) * std::max(max_vertical, h - vertical1.back()) * 2;
        std::cout << result << std::endl;
    }

    return 0;
}