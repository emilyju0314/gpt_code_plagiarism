#include <iostream>
#include <cmath>

int countPolycarpLikes(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if ((sqrt(i) == floor(sqrt(i)) || cbrt(i) == floor(cbrt(i))) {
            count++;
        }
    }
    return count;
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::cout << countPolycarpLikes(n) << std::endl;
    }

    return 0;
}