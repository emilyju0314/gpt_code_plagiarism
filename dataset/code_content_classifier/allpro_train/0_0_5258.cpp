#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int count = 0;
    for (int i = 1; i <= N; i++) {
        int firstDigitA = i / 1000;
        int lastDigitA = i % 10;
        if (firstDigitA == lastDigitA) {
            count++;
        }

        for (int j = 1; j <= N; j++) {
            int firstDigitB = j / 1000;
            int lastDigitB = j % 10;
            if (firstDigitA == lastDigitB && lastDigitA == firstDigitB) {
                count++;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}