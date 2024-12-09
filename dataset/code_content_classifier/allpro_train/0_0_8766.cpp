#include <iostream>
#include <string>

bool isRBSPossible(const std::string& s) {
    int openCount = 0;
    int missingCount = 0;
    for(char c : s) {
        if(c == '(') {
            openCount++;
        } else if(c == ')') {
            if(openCount > 0) {
                openCount--;
            } else {
                missingCount++;
            }
        }
    }
    
    if(missingCount == 1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        std::string s;
        std::cin >> s;
        
        if(isRBSPossible(s)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    
    return 0;
}