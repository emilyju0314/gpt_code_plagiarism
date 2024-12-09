#include <iostream>

int main() {
    int R, G;
    std::cin >> R >> G;
    
    int performance = 2 * G - R;
    
    std::cout << performance << std::endl;
    
    return 0;
}