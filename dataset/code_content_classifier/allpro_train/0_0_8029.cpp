#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;

    int n = input.size() + 1;
    long long sum = 0;
    long long current = 0;
    for (int i = 0; i < n; i++) {
        if (i == n-1 || input[i] == '>') {
            for (int j = i; j >= current; j--) {
                sum += j;
            }
            current = i + 1;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}