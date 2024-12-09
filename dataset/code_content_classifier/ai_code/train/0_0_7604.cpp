#include <iostream>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);

    for (int i = 0; i < input.length(); i++) {
        if (input.substr(i, 5) == "apple") {
            input.replace(i, 5, "peach");
        } else if (input.substr(i, 5) == "peach") {
            input.replace(i, 5, "apple");
        }
    }

    std::cout << input << std::endl;

    return 0;
}