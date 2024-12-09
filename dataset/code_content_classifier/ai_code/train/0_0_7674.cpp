#include <iostream>

bool isPossible(int a, int b) {
    if(a == b) {
        return a == 1; // Only possible if both scores are 1
    }
    
    int gcd = std::__gcd(a, b);
    int ratioA = a / gcd;
    int ratioB = b / gcd;
    
    while(ratioA % 2 == 0) {
        ratioA /= 2;
    }
    
    return ratioA == 1 && ratioB % 2 == 1;
}

int main() {
    int n;
    std::cin >> n;
    
    for(int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        
        if(isPossible(a, b)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    
    return 0;
}