#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;
    
    int count = 0;
    for (int i = 0; i < S.length(); i++) {
        for (int j = 0; j < S.length(); j++) {
            if (S[i] == S[j]) {
                count++;
            }
        }
    }
    
    std::cout << count << std::endl;
    
    return 0;
}