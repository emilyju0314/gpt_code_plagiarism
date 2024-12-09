#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    long long result = 0;
    for(int i = 0; i <= ceil(n/2.0); i++) {
        result += (n - i + 1) * (n - i + 2);
    }

    std::cout << result << std::endl;

    return 0;
}