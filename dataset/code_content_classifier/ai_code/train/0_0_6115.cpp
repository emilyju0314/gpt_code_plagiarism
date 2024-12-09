#include <iostream>
#include <vector>
#include <algorithm>

std::string predictOutcome(int n, std::vector<int>& cards) {
    std::sort(cards.begin(), cards.end(), std::greater<int>());
    
    int totalSum = 0;
    for(int i = 0; i < n; i++) {
        totalSum += cards[i];
    }
    
    int conanSum = 0;
    for(int i = 0; i < n; i++) {
        conanSum += cards[i];
        
        totalSum -= cards[i];
        if(conanSum > totalSum) {
            return "Conan";
        }
    }
    
    return "Agasa";
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> cards(n);
    for(int i = 0; i < n; i++) {
        std::cin >> cards[i];
    }
    
    std::string result = predictOutcome(n, cards);
    std::cout << result << std::endl;
    
    return 0;
}