#include <iostream>
#include <algorithm>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    
    int minimum = std::min({a, b, c});
    int maximum = std::max({a, b, c});
    
    std::cout << minimum << " " << maximum << std::endl;
    
    return 0;
}