#include <iostream>

int main() {
    int A, B, C, N;
    std::cin >> A >> B >> C >> N;

    int total_students = A + B - C;
    int not_passed = N - total_students;

    if (not_passed <= 0 || (A < C) || (B < C) || (total_students >= N)) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << not_passed << std::endl;
    }

    return 0;
}