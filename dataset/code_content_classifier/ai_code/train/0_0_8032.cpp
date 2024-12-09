#include <iostream>
#include <string>
#include <vector>
#include <cmath>

const int MOD = 1000000007;

int ABCNumber(const std::string& S) {
    int countQuestionMark = 0;
    long long sum = 0;
    
    for (char c : S) {
        if (c == '?') {
            countQuestionMark++;
        }
    }
    
    for (int i = 0; i < pow(3, countQuestionMark); i++) {
        std::vector<char> tempS = S;
        int number = i;
        
        for (int j = 0; j < S.length(); j++) {
            if (tempS[j] == '?') {
                int digit = number % 3;
                tempS[j] = "ABC"[digit];
                number /= 3;
            }
        }
        
        int triplets = 0;
        for (int i = 0; i < S.length(); i++) {
            if (tempS[i] == 'A') {
                for (int j = i + 1; j < S.length(); j++) {
                    if (tempS[j] == 'B') {
                        for (int k = j + 1; k < S.length(); k++) {
                            if (tempS[k] == 'C') {
                                triplets++;
                            }
                        }
                    }
                }
            }
        }
        
        sum = (sum + triplets) % MOD;
    }
    
    return sum;
}

int main() {
    std::string S;
    std::cin >> S;
    
    int result = ABCNumber(S);
    
    std::cout << result << std::endl;
    
    return 0;
}