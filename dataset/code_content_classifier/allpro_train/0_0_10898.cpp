#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;

    while (std::cin >> n) {
        if (n == -1) {
            break;
        }

        std::vector<int> quaternary;
        
        if (n == 0) {
            quaternary.push_back(0);
        } else {
            while (n > 0) {
                quaternary.push_back(n % 4);
                n /= 4;
            }
        }

        std::reverse(quaternary.begin(), quaternary.end());

        for (int digit : quaternary) {
            std::cout << digit;
        }

        std::cout << std::endl;
    }

    return 0;
}