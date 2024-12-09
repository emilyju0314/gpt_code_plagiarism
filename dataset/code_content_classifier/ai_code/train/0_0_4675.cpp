#include <iostream>
#include <string>

int main() {
    int A, B, X, N;
    std::cin >> A >> B >> X >> N;

    int length = X;
    for (int i = 0; i < N; i++) {
        std::string command;
        std::cin >> command;

        if (command == "nobiro") {
            length += A;
        } else if (command == "tidime") {
            length += B;
        } else if (command == "karero") {
            length = 0;
        }

        if (length < 0) {
            length = 0;
        }
    }

    std::cout << length << std::endl;

    return 0;
}