#include <iostream>

int main() {
    int A, B, C, K;
    std::cin >> A >> B >> C >> K;

    while (K > 0) {
        if (B <= A) {
            B *= 2;
            K--;
        } else if (C <= B) {
            C *= 2;
            K--;
        } else {
            break;
        }
    }

    if (B > A && C > B) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}