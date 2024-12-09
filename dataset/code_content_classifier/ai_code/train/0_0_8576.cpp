#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> s(n);
    std::unordered_map<int, int> count;
    
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
        count[s[i]]++;
    }
    
    std::cout << "YES" << std::endl;
    
    char currentSet = 'A';
    for (int i = 0; i < n; i++) {
        if (count[s[i]] == 1) {
            std::cout << currentSet;
            currentSet = (currentSet == 'A') ? 'B' : 'A';
        } else {
            std::cout << 'A';
        }
    }
    
    return 0;
}