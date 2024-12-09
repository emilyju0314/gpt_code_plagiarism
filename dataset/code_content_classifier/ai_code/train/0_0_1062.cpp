#include <iostream>
#include <string>
#include <cmath>

int minMoves(std::string s, char c) {
    int n = s.length();
    
    if(n == 1) {
        if(s[0] == c) {
            return 0;
        } else {
            return 1;
        }
    }
    
    int split = n/2;
    int left = 0, right = 0;
    
    for(int i = 0; i < split; i++) {
        if(s[i] != c) {
            left++;
        }
    }
    
    for(int i = split; i < n; i++) {
        if(s[i] != (c + 1)) {
            right++;
        }
    }
    
    return std::min(left + minMoves(s.substr(split, n - split), c + 1), right + minMoves(s.substr(0, split), c + 1));
}

int main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        int n;
        std::cin >> n;
        
        std::string s;
        std::cin >> s;
        
        std::cout << minMoves(s, 'a') << std::endl;
    }
    
    return 0;
}