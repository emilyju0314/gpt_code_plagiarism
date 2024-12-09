#include <iostream>
#include <vector>

bool canWin(int K, std::vector<long long>& N, std::vector<long long>& M) {
    long long XOR = 0;
    for(int i=0; i<K; i++) {
        XOR ^= N[i];
    }
    
    for(int i=0; i<K; i++) {
        long long max_possible_value = (M[i] - N[i]) / 2;
        if((XOR & max_possible_value) == max_possible_value) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int K;
    std::cin >> K;
    
    std::vector<long long> N(K);
    std::vector<long long> M(K);
    for(int i=0; i<K; i++) {
        std::cin >> N[i] >> M[i];
    }
    
    if(canWin(K, N, M)) {
        std::cout << "mo3tthi" << std::endl;
    } else {
        std::cout << "tubuann" << std::endl;
    }
    
    return 0;
}