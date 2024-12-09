#include <iostream>
#include <cmath>

int main() {
    int W, a, b;
    std::cin >> W >> a >> b;

    if(a <= b && b <= a+W) {
        std::cout << "0" << std::endl;
    } else if(b <= a && a <= b+W) {
        std::cout << "0" << std::endl;
    } else {
        int distance;
        if(a > b) {
            distance = a - (b + W);
        } else {
            distance = b - (a + W);
        }
        std::cout << std::abs(distance) << std::endl;
    }

    return 0;
}