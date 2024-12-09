#include <iostream>

int main() {
    int a1, a2;
    std::cin >> a1 >> a2;

    int minutes = 0;
    while(a1 > 0 && a2 > 0) {
        if(a1 <= a2) {
            a1 += 1;
            a2 -= 2;
        } else {
            a2 += 1;
            a1 -= 2;
        }
        minutes++;
    }

    std::cout << minutes << std::endl;

    return 0;
}