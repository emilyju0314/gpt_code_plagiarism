#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;
    
    int n = s.size();
    int cnt = 0;
    
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n-1-i]) {
            cnt++;
        }
    }
    
    if (cnt == 0) {
        std::cout << 0 << std::endl;
    } else if (cnt == 1) {
        std::cout << 1 << std::endl;
    } else if (cnt == 2) {
        std::cout << 3 << std::endl;
    } else if (n % 2 && cnt == 3) {
        std::cout << 3 << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    
    return 0;
}