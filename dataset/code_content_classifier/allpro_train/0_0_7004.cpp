#include <iostream>
#include <string>
#include <vector>

int count11Sequences(const std::string& number) {
    int count = 0;
    for (size_t i = 1; i <= number.size(); i++) {
        int num = std::stoi(number.substr(0, i));
        if (num % 11 == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    std::string number;
    while (std::cin >> number) {
        if (number == "0") {
            break;
        }
        int result = count11Sequences(number);
        std::cout << result << std::endl;
    }
    return 0;
}