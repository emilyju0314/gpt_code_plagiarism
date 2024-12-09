#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> candies(n);
    for(int i = 0; i < n; i++) {
        std::cin >> candies[i];
    }

    std::sort(candies.begin(), candies.end());

    if(n == 0) {
        std::cout << "YES" << std::endl;
        std::cout << "1\n1\n1\n1" << std::endl;
    } else if(n == 1) {
        std::cout << "YES" << std::endl;
        std::cout << candies[0] << std::endl;
        std::cout << candies[0] << std::endl;
        std::cout << candies[0] << std::endl;
    } else if(n == 2) {
        if(candies[0] * 3 == candies[1] * 2) {
            std::cout << "YES" << std::endl;
            std::cout << candies[1] * 3 - candies[0] * 2 << std::endl;
            std::cout << candies[0] * 2 << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    } else if(n == 3) {
        if(candies[0] == candies[2] && candies[1] * 2 == candies[0] + candies[2]) {
            std::cout << "YES" << std::endl;
            std::cout << candies[1] << std::endl;
            std::cout << candies[1] * 2 - candies[0] << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    } else {
        if(candies[0] + candies[3] == candies[1] + candies[2] && candies[3] - candies[0] == 3 * candies[1] - 3 * candies[0]) {
            std::cout << "YES" << std::endl;
            std::cout << candies[1] + candies[2] - candies[0] << std::endl;
            std::cout << candies[2] << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}