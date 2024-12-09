#include <iostream>
#include <string>

int main() {
    std::string date;
    std::cin >> date;
    
    if (date <= "2019/04/30") {
        std::cout << "Heisei" << std::endl;
    } else {
        std::cout << "TBD" << std::endl;
    }
    
    return 0;
}