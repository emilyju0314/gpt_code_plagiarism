#include <iostream>
#include <sstream>
#include <iomanip>

int main() {
    int s;
    std::cin >> s;

    for (int i = 0; i < s; i++) {
        std::string input;
        std::getline(std::cin >> std::ws, input);

        std::istringstream iss(input);
        int sum = 0;
        for (int j = 0; j < 9; j++) {
            int num;
            iss >> std::hex >> num;
            sum += num;
        }

        int key = sum & 0xFF; // Extract lowest 8 bits
        std::cout << std::hex << std::setfill('0') << std::setw(2) << key << std::endl;
    }

    return 0;
}