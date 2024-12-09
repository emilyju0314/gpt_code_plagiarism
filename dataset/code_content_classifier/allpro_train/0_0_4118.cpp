#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> ancient_numbers(n);
    for(int i = 0; i < n; i++) {
        std::cin >> ancient_numbers[i];
    }

    for(int i = 0; i < n; i++) {
        if(k % ancient_numbers[i] == 0) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }

    std::cout << "No" << std::endl;

    return 0;
}