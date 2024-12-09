#include <iostream>
#include <cmath>

int main() {
    int N;
    std::cin >> N;
    
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2, X, Y;
        std::cin >> x1 >> y1 >> x2 >> y2 >> X >> Y;
        
        int d1 = abs(x1 - X) + abs(y1 - Y);
        int d2 = abs(x2 - X) + abs(y2 - Y);
        
        if ((x1 == x2 && x2 == X && ((y1 < Y && y2 < Y) || (y1 > Y && y2 > Y))) || 
            (y1 == y2 && y2 == Y && ((x1 < X && x2 < X) || (x1 > X && x2 > X))) ||
            (abs(x1 - X) == abs(y1 - Y) && abs(x2 - X) == abs(y2 - Y))) {
            std::cout << "0" << std::endl;
        } else {
            if ((x1 == X && x2 == X) || (y1 == Y && y2 == Y)) {
                if (d1 > d2) {
                    std::cout << "1" << std::endl;
                } else {
                    std::cout << "0" << std::endl;
                }
            } else {
                if (d1 <= d2) {
                    std::cout << "1" << std::endl;
                } else {
                    std::cout << "2" << std::endl;
                }
            }
        }
    }
    
    return 0;
}