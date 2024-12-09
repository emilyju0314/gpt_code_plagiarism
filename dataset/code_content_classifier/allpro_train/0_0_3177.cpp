#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;
    
    // Print the first three characters of the string
    std::cout << S.substr(0, 3) << std::endl;
    
    return 0;
}