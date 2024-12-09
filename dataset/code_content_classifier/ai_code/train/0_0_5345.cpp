#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> X(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i];
    }

    // Find the middle point of the number line
    int middle = X[N / 2];

    // Calculate the minimum total stamina
    int totalStamina = 0;
    for (int i = 0; i < N; i++) {
        totalStamina += pow(X[i] - middle, 2);
    }

    std::cout << totalStamina << std::endl;

    return 0;
}