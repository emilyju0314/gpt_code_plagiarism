#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> laptops;
    for(int i = 0; i < n; i++) {
        int price, quality;
        std::cin >> price >> quality;
        laptops.push_back(std::make_pair(price, quality));
    }

    std::sort(laptops.begin(), laptops.end());

    for(int i = 1; i < n; i++) {
        if(laptops[i].second < laptops[i-1].second) {
            std::cout << "Happy Alex" << std::endl;
            return 0;
        }
    }

    std::cout << "Poor Alex" << std::endl;

    return 0;
}