#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;
    
    int max_price = 0;
    
    for (int i = 0; i < N; i++) {
        int A, B, C;
        std::cin >> A >> B >> C;
        
        if (A <= M) {
            int price = B * C;
            max_price = std::max(max_price, price);
        }
    }
    
    std::cout << max_price << std::endl;
    
    return 0;
}