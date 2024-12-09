#include <iostream>

int main() {
    int n, x, y, z;
    std::cin >> n >> x >> y >> z;
    
    int result = n*(x*z + ((n-1)*n*y)/2);
    
    std::cout << result << std::endl;
    
    return 0;
}