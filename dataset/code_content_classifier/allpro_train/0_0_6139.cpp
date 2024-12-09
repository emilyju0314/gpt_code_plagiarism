#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;

    std::string output = "";
    for (int i = 0; i < input.length(); i += 2) {
        char button = input[i];
        char direction = input[i + 1];

        if (button == '0') {
            if (direction == 'U') {
                output += "nn";
            } else {
                output += "d";
            }
        } else if (button == '1') {
            if (direction == 'T') {
                output += "a";
            } else if (direction == 'L') {
                output += "t";
            } else if (direction == 'U') {
                output += "n";
            } else if (direction == 'R') {
                output += "i";
            } else {
                output += "s";
            }
        } else if (button == '2') {
            if (direction == 'T') {
                output += "k";
            } else if (direction == 'L') {
                output += "t";
            } else if (direction == 'U') {
                output += "n";
            } else if (direction == 'R') {
                output += "i";
            } else {
                output += "s";
            }
        } else if (button == '3') {
            if (direction == 'T') {
                output += "s";
            } else if (direction == 'L') {
                output += "r";
            } else if (direction == 'U') {
                output += "t";
            } else if (direction == 'R') {
                output += "u";
            } else {
                output += "m";
            }
        } else if (button == '4') {
            if (direction == 'T') {
                output += "i";
            } else if (direction == 'L') {
                output += "n";
            } else if (direction == 'U') {
                output += "o";
            } else if (direction == 'R') {
                output += "h";
            } else {
                output += "y";
            }
        } else if (button == '5') {
            if (direction == 'T') {
                output += "u";
            } else if (direction == 'L') {
                output += "r";
            } else if (direction == 'U') {
                output += "f";
            } else if (direction == 'R') {
                output += "o";
            } else {
                output += "k";
            }
        } else if (button == '6') {
            if (direction == 'T') {
                output += "e";
            } else if (direction == 'L') {
                output += "h";
            } else if (direction == 'U') {
                output += "m";
            } else if (direction == 'R') {
                output += "a";
            } else {
                output += "t";
            }
        } else if (button == '7') {
            if (direction == 'T') {
                output += "h";
            } else if (direction == 'L') {
                output += "m";
            } else if (direction == 'U') {
                output += "i";
            } else if (direction == 'R') {
                output += "y";
            } else {
                output += "w";
            }
        } else if (button == '8') {
            if (direction == 'T') {
                output += "y";
            } else if (direction == 'L') {
                output += "s";
            } else if (direction == 'U') {
                output += "r";
            } else if (direction == 'R') {
                output += "u";
            } else {
                output += "w";
            }
        } else if (button == '9') {
            if (direction == 'T') {
                output += "w";
            } else if (direction == 'L') {
                output += "y";
            } else if (direction == 'U') {
                output += "r";
            } else if (direction == 'R') {
                output += "u";
            } else {
                output += "f";
            }
        }
    }

    std::cout << output << std::endl;

    return 0;
}