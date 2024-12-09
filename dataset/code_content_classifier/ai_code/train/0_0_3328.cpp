#include <iostream>
#include <vector>
#include <algorithm>

int s(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    std::vector<int> solutions;
    for (int x = 1; x < 109; x++) {
        if (x == b * s(x) + c) {
            solutions.push_back(x);
        }
    }

    std::cout << solutions.size() << std::endl;
    for (int solution : solutions) {
        std::cout << solution << " ";
    }

    return 0;
}