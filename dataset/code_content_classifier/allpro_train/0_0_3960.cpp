#include <iostream>

int main() {
    int X, Y;
    std::cin >> X >> Y;

    for(int i = 0; i <= X; i++) {
        int legs = i * 2 + (X - i) * 4;
        if(legs == Y) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }

    std::cout << "No" << std::endl;
    return 0;
}