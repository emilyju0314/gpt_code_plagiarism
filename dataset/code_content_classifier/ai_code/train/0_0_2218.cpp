#include <iostream>
#include <string>

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;
    
    std::string companies;
    std::cin >> companies;
    
    if(companies[a-1] == companies[b-1]) {
        std::cout << "0" << std::endl;
    } else {
        std::cout << "1" << std::endl;
    }
    
    return 0;
}