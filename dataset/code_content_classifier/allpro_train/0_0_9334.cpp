#include <iostream>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    int minLen = INT_MAX;
    int maxLen = 0;
    
    for(int i = 0; i < N; i++) {
        int len;
        std::cin >> len;
        minLen = std::min(minLen, len);
        maxLen = std::max(maxLen, len);
    }

    if(minLen == maxLen) {
        std::cout << 2 << std::endl;
    } else {
        std::cout << 1 << std::endl;
    }

    return 0;
}