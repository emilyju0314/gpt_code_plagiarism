#include <iostream>

int main() {
    int N, A, B;
    std::cin >> N >> A >> B;

    int min_expense = N * A < B ? N * A : B;
    std::cout << min_expense << std::endl;

    return 0;
}