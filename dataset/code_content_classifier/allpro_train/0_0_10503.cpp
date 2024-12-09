#include <iostream>

int main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        int n;
        std::cin >> n;
        
        if(n % 2 == 0 && n % 4 != 0) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    
    return 0;
}