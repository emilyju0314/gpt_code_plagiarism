#include <iostream>
#include <string>

int main() {
    int a;
    std::string s;
    
    std::cin >> a >> s;
    
    if(a < 3200) {
        std::cout << "red" << std::endl;
    } else {
        std::cout << s << std::endl;
    }
    
    return 0;
}