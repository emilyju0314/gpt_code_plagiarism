#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<std::string> cities(n);

    for (int i = 0; i < n; i++) {
        std::cin >> cities[i];
    }

    char separator;
    std::cin >> separator;

    std::sort(cities.begin(), cities.end());

    for (int i = 0; i < n / 2; i++) {
        std::cout << cities[i] << separator << cities[i + n / 2] << std::endl;
    }

    return 0;
}