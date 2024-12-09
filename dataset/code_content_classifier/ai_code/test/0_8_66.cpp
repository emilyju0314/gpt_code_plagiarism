#include <iostream>

int lastRestaurant(int N, int A, int B, std::string D_A, std::string D_B) {
    if(N == 1) {
        return 0;
    }
    
    if(D_A == D_B || A == B) {
        return N % 2 == 0 ? 0 : 1;
    } else {
        return (A + N - B - 1) % N;
    }
}

int main() {
    int T;
    std::cin >> T;
    
    for(int i = 0; i < T; i++) {
        int N, A, B;
        std::string D_A, D_B;
        
        std::cin >> N >> A >> B >> D_A >> D_B;
        
        int result = lastRestaurant(N, A, B, D_A, D_B);
        std::cout << result << std::endl;
    }
    
    return 0;
}