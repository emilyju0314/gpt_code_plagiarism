#include <iostream>
#include <string>

std::string f(int X, int Y, int Z) {
    std::string result;

    while (X > 0 && Y > 0 && Z > 0) {
        if (X >= Y && X >= Z) {
            result += 'a';
            X--;
        } else if (Y >= X && Y >= Z) {
            result += 'b';
            Y--;
        } else {
            result += 'c';
            Z--;
        }
    }

    while (X > 0) {
        result += 'a';
        X--;
    }
    
    while (Y > 0) {
        result += 'b';
        Y--;
    }

    while (Z > 0) {
        result += 'c';
        Z--;
    }

    return result;
}

int main() {
    int X, Y, Z;
    std::cin >> X >> Y >> Z;

    std::string result = f(X, Y, Z);
    std::cout << result << std::endl;

    return 0;
}