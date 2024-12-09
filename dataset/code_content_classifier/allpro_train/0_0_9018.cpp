#include <iostream>
#include <vector>

int countPairs(int l, int r) {
    int xorsum = l ^ r;
    int msb_pos = 0;
    
    while (xorsum) {
        xorsum >>= 1;
        msb_pos++;
    }
    
    int pairs = (1 << msb_pos) - 1;
    
    return pairs;
}

int main() {
    int t;
    std::cin >> t;
    
    std::vector<std::pair<int, int>> testcases(t);
    for (int i = 0; i < t; i++) {
        int l, r;
        std::cin >> l >> r;
        testcases[i] = std::make_pair(l, r);
    }
    
    for (int i = 0; i < t; i++) {
        int l = testcases[i].first;
        int r = testcases[i].second;
        int pairs = countPairs(l, r);
        std::cout << pairs << std::endl;
    }
    
    return 0;
}