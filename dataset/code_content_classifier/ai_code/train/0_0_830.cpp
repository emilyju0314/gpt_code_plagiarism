#include <iostream>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    int rickTime = b;
    int mortyTime = d;
    
    while (rickTime != mortyTime) {
        if (rickTime < mortyTime) {
            rickTime += a;
        } else {
            mortyTime += c;
        }
        
        if (rickTime > 100 && mortyTime > 100) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }
    
    std::cout << rickTime << std::endl;

    return 0;
}