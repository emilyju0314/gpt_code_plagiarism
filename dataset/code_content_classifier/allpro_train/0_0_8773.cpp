#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;
    
    int n = s.length();
    int ans = 0;
    
    for (int len = n; len > 0; --len) {
        for (int i = 0; i + len <= n; ++i) {
            std::string substr = s.substr(i, len);
            size_t found = s.find(substr, i + 1);
            if (found != std::string::npos) {
                ans = len;
                break;
            }
        }
        if (ans > 0) {
            break;
        }
    }
    
    std::cout << ans << std::endl;
    
    return 0;
}