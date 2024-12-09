#include <iostream>
#include <string>

int main() {
    int n, t;
    std::cin >> n >> t;
    
    std::string s;
    std::cin >> s;
    
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (s[j] == 'B' && s[j+1] == 'G') {
                std::swap(s[j], s[j+1]);
                j++;
            }
        }
    }
    
    std::cout << s << std::endl;
    
    return 0;
}