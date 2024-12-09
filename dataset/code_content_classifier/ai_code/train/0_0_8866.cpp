#include <iostream>
#include <unordered_set>

int main() {
    int n;
    std::cin >> n;
    
    std::unordered_set<int> blockSet;
    for(int i = 1; i <= 106; i++) {
        blockSet.insert(i);
    }
    
    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        blockSet.erase(x);
    }
    
    std::cout << blockSet.size() << std::endl;
    
    for(int block : blockSet) {
        std::cout << block << " ";
    }
    
    return 0;
}