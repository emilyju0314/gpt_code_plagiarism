#include <iostream>
#include <vector>
#include <string>

int main() {
    int a;
    std::cin >> a;
    
    std::string s;
    std::cin >> s;
    
    long long ans = 0;
    
    for (int i = 0; i < s.size(); i++) {
        int cur = 0;
        
        for (int j = i; j < s.size(); j++) {
            cur += (s[j] - '0');
            
            if (cur > a) {
                break;
            }
            
            if (a % cur == 0) {
                for (int k = s.size() - 1; k >= j + 1; k--) {
                    if ((a / cur) % (s[k] - '0') == 0) {
                        ans++;
                    }
                }
            }
        }
    }
    
    std::cout << ans << std::endl;
    
    return 0;
}