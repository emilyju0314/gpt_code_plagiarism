#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;

    int min_pieces = A * B;
    std::cout << min_pieces << std::endl;

    return 0;
}