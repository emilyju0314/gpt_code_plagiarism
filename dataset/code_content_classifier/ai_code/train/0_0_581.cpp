#include <iostream>
#include <vector>
#include <algorithm>

int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int K;
    std::cin >> K;

    std::vector<int> snukeNumbers;
    for (int i = 1; snukeNumbers.size() < K; i++) {
        int sumN = sumOfDigits(i);
        bool isSnuke = true;
        for (int m = i + 1; m < i + sumN; m++) {
            if (i * sumOfDigits(m) > m * sumN) {
                isSnuke = false;
                break;
            }
        }
        if (isSnuke) {
            snukeNumbers.push_back(i);
        }
    }

    for (int i = 0; i < K; i++) {
        std::cout << snukeNumbers[i] << std::endl;
    }

    return 0;
}