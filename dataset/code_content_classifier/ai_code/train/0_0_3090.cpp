#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;
    
    if(S[S.length()-1] == 's'){
        S += "es";
    } else {
        S += "s";
    }
    
    std::cout << S << std::endl;
    
    return 0;
}