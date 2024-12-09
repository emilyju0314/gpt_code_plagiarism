#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> cards(n);
    for(int i = 0; i < n; i++) {
        std::cin >> cards[i];
    }
    
    std::sort(cards.begin(), cards.end());
    
    for(int i = 0; i < n/2; i++) {
        if(cards[i] != cards[n/2 + i]) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    
    std::cout << "YES" << std::endl;
    std::cout << cards[0] << " " << cards[n/2] << std::endl;
    
    return 0;
}