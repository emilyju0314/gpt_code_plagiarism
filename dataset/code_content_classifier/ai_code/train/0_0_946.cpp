#include <iostream>
#include <vector>
#include <algorithm>

bool solve(std::vector<int>& cards) {
    std::sort(cards.begin(), cards.end());
    
    do {
        std::vector<int> played;
        bool valid = true;
        for(int i = 0; i < cards.size(); i++) {
            bool conquer = false;
            for(int j = 0; j < played.size(); j++) {
                if(cards[i] % played[j] == 0) {
                    conquer = true;
                    break;
                }
            }
            if(!conquer) {
                valid = false;
                break;
            }
            played.push_back(cards[i]);
        }
        
        if(valid) {
            for(int i = 0; i < cards.size(); i++) {
                if(i > 0) std::cout << " ";
                std::cout << cards[i];
            }
            std::cout << std::endl;
            return true;
        }
    } while(std::next_permutation(cards.begin(), cards.end()));
    
    return false;
}

int main() {
    int n;
    while(std::cin >> n && n != 0) {
        std::vector<int> cards(n);
        for(int i = 0; i < n; i++) {
            std::cin >> cards[i];
        }
        
        if(!solve(cards)) {
            std::cout << "No" << std::endl;
        }
    }
    
    return 0;
}