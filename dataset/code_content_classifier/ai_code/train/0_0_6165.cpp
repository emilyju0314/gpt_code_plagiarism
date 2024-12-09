#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    int max_soldiers = (n*m)/2;
    std::cout << max_soldiers << std::endl;

    return 0;
}