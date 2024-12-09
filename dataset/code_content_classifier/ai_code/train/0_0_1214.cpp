#include <iostream>
#include <string>

bool isWellFormed(const std::string& s) {
    int balance = 0;
    for(char c : s) {
        if(c == '(') {
            balance++;
        } else if(c == ')') {
            balance--;
        }
        
        if(balance < 0) {
            return false;
        }
    }
    
    return balance == 0;
}

int main() {
    int q;
    std::cin >> q;
    
    std::string S;
    for(int i = 0; i < q; i++) {
        int p, n;
        char c;
        std::cin >> p >> c >> n;
        
        while(S.size() < p) {
            S += ' ';
        }
        
        S.insert(p, n, c);
        
        if(isWellFormed(S)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    
    return 0;
}