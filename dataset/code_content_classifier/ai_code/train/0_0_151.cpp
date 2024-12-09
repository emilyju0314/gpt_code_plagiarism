#include <iostream>
#include <string>

int main() {
    std::string X;
    std::cin >> X;

    int count = 0;
    int index = 0;
    while (true) {
        index = X.find("ST", index);
        if (index == std::string::npos) {
            break;
        }
        X.erase(index, 2);
        count += 2;
    }

    std::cout << count << std::endl;

    return 0;
}