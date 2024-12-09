#include <iostream>
#include <cmath>

int main() {
    int b, n, c;
    std::cin >> b >> n >> c;

    long long totalNumbers = std::pow(b, n-1);
    int numbersOnLastPage = totalNumbers % c;

    std::cout << (numbersOnLastPage == 0 ? c : numbersOnLastPage) << std::endl;

    return 0;
}