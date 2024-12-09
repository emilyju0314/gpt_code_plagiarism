#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::string input;
    std::getline(std::cin, input);
    
    std::istringstream iss(input);
    std::vector<int> numbers;
    int num;
    while (iss >> num) {
        numbers.push_back(num);
    }

    int result = numbers[0] * (numbers[1] + numbers[2] + numbers[3] + numbers[4]);
    
    std::cout << result << std::endl;

    return 0;
}