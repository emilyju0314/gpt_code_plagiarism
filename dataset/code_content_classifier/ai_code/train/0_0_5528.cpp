#include <iostream>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int a, b;

    while (std::cin >> a >> b && (a != 0 || b != 0)) {
        int steps = 0;
        int result = gcd(a, b);

        std::cout << result << " ";

        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
            steps++;
        }

        std::cout << steps << std::endl;
    }

    return 0;
}