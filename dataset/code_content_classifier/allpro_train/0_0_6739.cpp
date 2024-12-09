#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> frequencyOperation(const std::vector<int>& S) {
    std::vector<int> C(S.size(), 0); // Initialize C with zeros

    std::unordered_map<int, int> frequencyCount; // Store the frequency of each element in S
    for(int i = 0; i < S.size(); i++) {
        frequencyCount[S[i]]++;
        C[i] = frequencyCount[S[i]]; // Update C with the frequency of each element
    }

    return C;
}

std::vector<int> fixedPointSequence(const std::vector<int>& S) {
    std::vector<int> P = S; // Initialize P with the sequence S
    
    std::unordered_map<int, int> frequencyCount;
    while(true) {
        frequencyCount.clear();
        std::vector<int> C = frequencyOperation(P);

        if(C == P) { // If C is the same as P, it is a fixed point
            break;
        }

        P = C; // Update P with the result of the frequency operation
    }

    return P;
}

int main() {
    int n;
    while(std::cin >> n) {
        if(n == 0) {
            break;
        }

        std::vector<int> S(n);
        for(int i = 0; i < n; i++) {
            std::cin >> S[i];
        }

        std::vector<int> P = fixedPointSequence(S);
        std::cout << P.size() << std::endl;

        for(int i = 0; i < P.size(); i++) {
            std::cout << P[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}