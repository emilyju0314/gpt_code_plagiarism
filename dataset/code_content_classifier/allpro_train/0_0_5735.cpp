#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::string input;
    std::cin >> input;

    std::string result = "$";
    
    if (input[0] == '-') {
        result += "(";
        input.erase(input.begin());
    }

    size_t pos = input.find(".");
    if (pos == std::string::npos) {
        input += ".00";
    } else if (input.size() - pos == 1) {
        input += "00";
    } else if (input.size() - pos == 2) {
        input += "0";
    } else if (input.size() - pos > 3) {
        input = input.substr(0, pos + 3);
    }

    pos = input.size() - 3;

    while (pos > 0) {
        input.insert(pos, 1, ',');
        pos -= 3;
    }

    result += input;

    if (result[0] == '(') {
        result += ")";
    }

    std::cout << result << std::endl;

    return 0;
}