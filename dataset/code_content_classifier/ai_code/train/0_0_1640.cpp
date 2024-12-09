#include <iostream>
#include <string>

int main() {
    std::string input;

    while (std::getline(std::cin, input)) {
        int R1 = 0;
        int R2 = 0;
        char R3 = ' ';

        bool error = false;

        for (char c : input) {
            if (c >= '0' && c <= '9') {
                R2 = R2 * 10 + (c - '0');
                if (R2 > 9999) {
                    error = true;
                    break;
                }
            } else if (c == '+' || c == '-' || c == '*') {
                if (R3 != ' ') {
                    if (R3 == '+') {
                        R1 += R2;
                    } else if (R3 == '-') {
                        R1 -= R2;
                    } else if (R3 == '*') {
                        R1 *= R2;
                    }

                    if (R1 < 0 || R1 > 9999) {
                        error = true;
                        break;
                    }
                }

                R2 = 0;
                R3 = c;
            } else if (c == '=') {
                if (R3 == '+') {
                    R1 += R2;
                } else if (R3 == '-') {
                    R1 -= R2;
                } else if (R3 == '*') {
                    R1 *= R2;
                }

                if (R1 < 0 || R1 > 9999) {
                    error = true;
                    break;
                }

                std::cout << (error ? "E" : std::to_string(R1)) << std::endl;

                R1 = 0;
                R2 = 0;
                R3 = ' ';
                error = false;
            }
        }
    }

    return 0;
}