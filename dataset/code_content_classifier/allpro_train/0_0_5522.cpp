#include <iostream>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    int ans = 100000;

    for (int i = 1; i < N; i++) {
        int A = i;
        int B = N - i;

        int sumOfDigitsA = 0;
        int sumOfDigitsB = 0;

        while (A > 0) {
            sumOfDigitsA += A % 10;
            A /= 10;
        }

        while (B > 0) {
            sumOfDigitsB += B % 10;
            B /= 10;
        }

        ans = std::min(ans, sumOfDigitsA + sumOfDigitsB);
    }

    std::cout << ans << std::endl;

    return 0;
}