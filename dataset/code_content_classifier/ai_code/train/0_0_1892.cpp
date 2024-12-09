#include <iostream>
#include <string>

int main() {
    int N, Q;
    std::string U;
    
    std::cin >> N;
    std::cin >> U;
    std::cin >> Q;
    
    while (Q--) {
        std::string query;
        std::cin >> query;
        
        if (query == "set") {
            int x, y;
            char z;
            std::cin >> x >> y >> z;
            
            for (int i = x - 1; i < y; i++) {
                U[i] = z;
            }
        } else if (query == "comp") {
            int a, b, c, d;
            std::cin >> a >> b >> c >> d;
            
            std::string S = U.substr(a - 1, b - a + 1);
            std::string T = U.substr(c - 1, d - c + 1);
            
            if (S < T) {
                std::cout << "s" << std::endl;
            } else if (T < S) {
                std::cout << "t" << std::endl;
            } else {
                std::cout << "e" << std::endl;
            }
        }
    }
    
    return 0;
}