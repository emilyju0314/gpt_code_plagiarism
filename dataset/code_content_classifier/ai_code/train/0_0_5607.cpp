#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;
    
    int hugs = 0;
    int n = s.length();
    
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n-1-i]) {
            hugs++;
        }
    }
    
    std::cout << hugs << std::endl;
    
    return 0;
}