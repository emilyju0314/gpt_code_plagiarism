#include <iostream>
#include <string>

bool checkEquivalence(std::string a, std::string b) {
    if (a == b) {
        return true;
    } else {
        int n = a.length();
        std::string a1 = a.substr(0, n/2);
        std::string a2 = a.substr(n/2, n/2);
        std::string b1 = b.substr(0, n/2);
        std::string b2 = b.substr(n/2, n/2);
        
        if ((checkEquivalence(a1, b1) && checkEquivalence(a2, b2)) || (checkEquivalence(a1, b2) && checkEquivalence(a2, b1))) {
            return true;
        } else {
            return false;
        }
    }
}

int main() {
    std::string a, b;
    std::cin >> a >> b;
    
    if (checkEquivalence(a, b)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}