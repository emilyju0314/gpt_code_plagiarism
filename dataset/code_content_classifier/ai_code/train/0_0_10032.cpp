#include <iostream>
#include <string>

int main() {
    int a, b;
    
    while (std::cin >> a >> b) {
        int sum = a + b;
        std::string sumStr = std::to_string(sum);
        std::cout << sumStr.length() << std::endl;
    }
    
    return 0;
}