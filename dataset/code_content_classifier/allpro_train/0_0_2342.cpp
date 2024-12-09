#include <iostream>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);

    for (char &c : input) {
        if (islower(c)) {
            c = toupper(c);
        } else if (isupper(c)) {
            c = tolower(c);
        }
    }

    std::cout << input << std::endl;

    return 0;
}