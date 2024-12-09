#include <iostream>
#include <string>

int main() {
    std::string input;
    int sum = 0;

    while (getline(std::cin, input)) {
        for (int i = 0; i < input.length(); ++i) {
            if (isdigit(input[i])) {
                int num = 0;
                while (isdigit(input[i])) {
                    num = num * 10 + (input[i] - '0');
                    ++i;
                }
                sum += num;
            }
        }
    }

    std::cout << sum << std::endl;

    return 0;
}