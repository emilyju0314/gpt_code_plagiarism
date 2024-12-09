#include <iostream>

int main() {
    int n, m, i, j, a, b;
    std::cin >> n >> m >> i >> j >> a >> b;

    int min_moves = std::max({(i-1)/a, (j-1)/b, (n-i)/a, (m-j)/b});

    if ((i + a*min_moves <= 0 || i + a*min_moves > n) || 
        (j + b*min_moves <= 0 || j + b*min_moves > m)) {
        std::cout << "Poor Inna and pony!" << std::endl;
    } else {
        std::cout << min_moves << std::endl;
    }

    return 0;
}