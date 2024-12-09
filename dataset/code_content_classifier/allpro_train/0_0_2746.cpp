#include <iostream>
#include <string>

int main() {
    std::string S, T, U;
    int A, B;
    std::cin >> S >> T >> A >> B >> U;

    if (S == U) {
        A--;
    } else {
        B--;
    }
    
    std::cout << A << " " << B << std::endl;

    return 0;
}