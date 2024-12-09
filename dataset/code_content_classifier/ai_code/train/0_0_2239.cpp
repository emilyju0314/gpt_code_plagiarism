#include <iostream>
#include <set>
#include <cmath>

bool isPowerOf6(long long num) {
    double root = std::cbrt(num);
    return root == std::round(root);
}

int main() {
    int N;
    std::cin >> N;

    std::set<long long> numbers;
    for (int i = 0; i < N; i++) {
        long long num;
        std::cin >> num;
        numbers.insert(num);
    }

    int count = 0;
    for(auto it = numbers.begin(); it != numbers.end(); it++) {
        if (!isPowerOf6(*it)) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}