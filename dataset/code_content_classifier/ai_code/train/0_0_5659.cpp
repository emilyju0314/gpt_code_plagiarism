#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    if (n < m) {
        std::swap(n, m);
    }

    int petyasPoints = 0;
    int vasyasPoints = 0;

    // Petya will maximize the number of pairs of neighboring cubes of the same color
    // Vasya will minimize the number of pairs of neighboring cubes of the same color
    petyasPoints = std::min(n, m);
    
    if (n == m) {
        vasyasPoints = n;
    } else {
        vasyasPoints = n - m;
    }

    std::cout << petyasPoints << " " << vasyasPoints << std::endl;

    return 0;
}