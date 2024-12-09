#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;

    int sum = 0;
    for(char c : input) {
        if(isalpha(c)) {
            if(isupper(c)) {
                sum += c - 'A' + 1;
            } else {
                sum -= c - 'a' + 1;
            }
        }
    }

    std::cout << sum << std::endl;

    return 0;
}