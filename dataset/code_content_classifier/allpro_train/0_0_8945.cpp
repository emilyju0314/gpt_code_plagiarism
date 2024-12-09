#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int d;
    std::cin >> d;
    
    std::string s;
    std::cin >> s;
    
    int n = s.size();
    
    std::string t = s;
    
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] < 'z') {
            t[i] = s[i] + 1;
            break;
        }
    }
    
    if (t <= s) {
        std::cout << "Impossible" << std::endl;
    } else {
        int palin_len = 0;
        
        for (int i = 0; i < n - d + 1; i++) {
            if (s[i] != s[i+d-1]) {
                palin_len = d - 1;
            }
        }
        
        for (int i = 0; i < n - palin_len - 1; i++) {
            if (t[i] == t[i + palin_len + 1]) {
                char c = 'a';
                while (c == t[i] || c == t[i + palin_len + 1]) {
                    c++;
                }
                t[i + palin_len + 1] = c;
            }
        }
        
        std::cout << t << std::endl;
    }
    
    return 0;
}