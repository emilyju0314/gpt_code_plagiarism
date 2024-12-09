#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;

    int n = S.length();
    int length = 0;

    for (int i = n/2; i > 0; i--) {
        if (S.substr(0,i) == S.substr(i, i)) {
            length = 2 * i;
            break;
        }
    }

    std::cout << length << std::endl;

    return 0;
}