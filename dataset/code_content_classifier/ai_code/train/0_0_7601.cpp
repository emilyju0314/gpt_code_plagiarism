#include <iostream>

int main() {
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    int start = std::max(A, C);
    int end = std::min(B, D);

    if(start < end) {
        std::cout << end - start << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }

    return 0;
}