#include <iostream>
#include <cmath>

int main() {
    int N;
    std::cin >> N;
    
    for (int i = 0; i < N; i++) {
        int dx, dy;
        int x = 0, y = 0;
        while (true) {
            std::cin >> dx >> dy;
            if (dx == 0 && dy == 0) {
                break;
            }
            x += dx;
            y += dy;
        }
        std::cout << x << " " << y << std::endl;
    }
    
    return 0;
}