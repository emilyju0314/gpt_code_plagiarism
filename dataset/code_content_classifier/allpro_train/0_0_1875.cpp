#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> candies(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> candies[i];
    }

    int square_count = 0;
    int non_square_count = 0;

    for(int i = 0; i < n; ++i) {
        int root = sqrt(candies[i]);
        if(root * root == candies[i]) {
            square_count++;
        } else {
            non_square_count++;
        }
    }

    if(square_count >= n/2) {
        std::cout << square_count - n/2 << std::endl;
    } else {
        std::cout << non_square_count - (n/2 - square_count) << std::endl;
    }

    return 0;
}