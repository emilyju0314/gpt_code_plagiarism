#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int N, Q;
    std::string S;
    
    std::cin >> N >> Q;
    std::cin >> S;
    
    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        std::string sub = S.substr(L-1, R-L+1);
        
        int longestX = 0;
        for(int j = 0; j < sub.length(); j++) {
            if(sub[j] == 'a' || sub[j] == 'i' || sub[j] == 'u' || sub[j] == 'e' || sub[j] == 'o') {
                longestX = std::max(longestX, 1);
            } else if(sub[j] == sub[j+1]) {
                longestX = std::max(longestX, 2);
            } else if(sub[j] == sub[j+2]) {
                longestX = std::max(longestX, 3);
            }
        }
        
        std::cout << longestX << std::endl;
    }
    
    return 0;
}