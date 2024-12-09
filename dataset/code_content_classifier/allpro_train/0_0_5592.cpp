#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int mishkaWins = 0, chrisWins = 0;

    for (int i = 0; i < n; i++) {
        int mi, ci;
        std::cin >> mi >> ci;

        if (mi > ci) {
            mishkaWins++;
        } else if (ci > mi) {
            chrisWins++;
        }
    }

    if (mishkaWins > chrisWins) {
        std::cout << "Mishka" << std::endl;
    } else if (chrisWins > mishkaWins) {
        std::cout << "Chris" << std::endl;
    } else {
        std::cout << "Friendship is magic!^^" << std::endl;
    }

    return 0;
}