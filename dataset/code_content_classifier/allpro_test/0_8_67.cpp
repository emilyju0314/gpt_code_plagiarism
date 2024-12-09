#include <iostream>
#include <cmath>

int main() {
    int N;
    double P;
    std::cin >> N >> P;

    int x = 0;
    while(pow((N-x)/N, 2) >= 1 - P) {
        x++;
    }

    std::cout << x << std::endl;

    return 0;
}