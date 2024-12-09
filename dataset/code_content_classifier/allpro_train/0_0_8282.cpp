#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> cards(n);
    for (int i = 0; i < n; i++) {
        std::cin >> cards[i];
    }
    
    int count = 0;
    int min_num = cards[0];
    
    for (int i = 0; i < n; i++) {
        if (cards[i] < min_num) {
            min_num = cards[i];
        }
        count++;
    }
    
    std::cout << count << std::endl;
    
    return 0;
}