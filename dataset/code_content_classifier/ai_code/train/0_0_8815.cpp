#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;

    std::string target = "CODEFESTIVAL2016";
    int count = 0;
    
    for (int i = 0; i < S.length(); i++) {
        if (S[i] != target[i]) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}