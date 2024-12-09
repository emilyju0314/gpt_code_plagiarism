#include <iostream>
#include <string>
#include <vector>

std::string addTwoLargeNumbers(std::string num1, std::string num2) {
    std::string result = "";
    int carry = 0;
    
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    
    while (i >= 0 || j >= 0) {
        int sum = carry;
        if (i >= 0) {
            sum += num1[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += num2[j] - '0';
            j--;
        }
        
        result = std::to_string(sum % 10) + result;
        carry = sum / 10;
    }
    
    if (carry) {
        result = std::to_string(carry) + result;
    }
    
    if (result.size() > 80) {
        return "overflow";
    } else {
        return result;
    }
}

int main() {
    int N;
    std::cin >> N;
    
    for (int i = 0; i < N; i++) {
        std::string num1, num2;
        std::cin >> num1 >> num2;
        
        std::string sum = addTwoLargeNumbers(num1, num2);
        std::cout << sum << std::endl;
    }
    
    return 0;
}