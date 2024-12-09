#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    int x1, y1, x2, y2;
    bool first_black = false;

    for (int i = 0; i < n; i++) {
        int x, y;
        std::cout << "0 0" << std::endl;
        std::string color;
        std::cin >> color;
        
        if (i == 0 && color == "black") {
            first_black = true;
        }
    }

    if (first_black) {
        x1 = 0; y1 = 1;
        x2 = 1; y2 = 0;
    } else {
        x1 = 0; y1 = 0;
        x2 = 1; y2 = 1;
    }

    std::cout << x1 << " " << y1 << std::endl;
    std::cout << x2 << " " << y2 << std::endl;

    return 0;
}