#include <iostream>
#include <string>
#include <algorithm>

std::string multiply(std::string num1, std::string num2) {
    int m = num1.size();
    int n = num2.size();
    
    std::string result(m + n, '0');
    
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int temp = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0');
            result[i + j + 1] = temp % 10 + '0';
            result[i + j] += temp / 10;
        }
    }
    
    auto it = result.find_first_not_of('0');
    if (it != std::string::npos) {
        return result.substr(it);
    }
    
    return "0";
}

int main() {
    std::string num1, num2;
    std::cin >> num1 >> num2;
    
    bool isNegative = false;
    if (num1[0] == '-') {
        isNegative = !isNegative;
        num1 = num1.substr(1);
    }
    if (num2[0] == '-') {
        isNegative = !isNegative;
        num2 = num2.substr(1);
    }

    std::string result = multiply(num1, num2);
    
    if (isNegative && result != "0") {
        std::cout << "-" << result << std::endl;
    } else {
        std::cout << result << std::endl;
    }
    
    return 0;
}