#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::string s;
    std::cin >> s;
    
    std::vector<int> pos(m);
    
    for (int i = 0; i < m; i++) {
        pos[s[i] - 'a'] = i;
    }
    
    int slowness = 0;
    
    for (int i = 1; i < n; i++) {
        int current = s[i] - 'a';
        int prev = s[i-1] - 'a';
        
        slowness += std::min(std::abs(pos[current] - pos[prev]), m - std::abs(pos[current] - pos[prev]));
    }
    
    std::cout << slowness << std::endl;
    
    return 0;
}