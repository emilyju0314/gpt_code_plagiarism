#include <iostream>

std::string generateBrainfuckProgram(std::string expression) {
    std::string program;
    int total = 0;

    for (char c : expression) {
        if (c == '+') {
            program += "+";
            total++;
        } else if (c == '-') {
            program += "-";
            total--;
        } else {
            int diff = c - '0' - total;
            total = c - '0';
            if (diff > 0) {
                program.append(diff, '+');
            } else if (diff < 0) {
                program.append(-diff, '-');
            }
        }
    }

    program += ".";

    return program;
}

int main() {
    std::string expression;
    std::getline(std::cin, expression);

    std::string brainfuckProgram = generateBrainfuckProgram(expression);
    std::cout << brainfuckProgram << std::endl;

    return 0;
}