#include <iostream>
#include <string>
#include <bitset>

std::string addBinary(std::string a, std::string b) {
    std::string result; // To store the sum bits
    int carry = 0; // Initialize the carry

    while (a.length() < b.length()) {
        a = "0" + a; // Add zeros to equalize the length of strings
    }
    while (b.length() < a.length()) {
        b = "0" + b; // Add zeros to equalize the length of strings
    }
    
    for (int i = a.length() - 1; i >= 0; --i) { // Traverse the strings
        int bit1 = a[i] - '0'; // Get the current bit from a
        int bit2 = b[i] - '0'; // Get the current bit from b
        int sum = bit1 ^ bit2 ^ carry; // XOR operation
        result = std::to_string(sum) + result; // Append the sum bit to the result
        carry = (bit1 & bit2) | (bit1 & carry) | (bit2 & carry); // Compute the new carry
    }

    if (carry) {
        result = "1" + result; // Add the carry to the result
    }

    return result;
}

std::string calculateS(int n, std::string significand, std::string un) {
    std::string s = significand;
    
    for (int i = 1; i < n; ++i) {
        s = addBinary(s, s);
    }
    
    return addBinary(un + "1", s); // Add 1 to the significand based on format description
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::string significand;
        std::cin >> significand; // Read the string representing the significand

        std::string un = "1"; // Unsigned unary number (1s with length 12)
        for (int i = 0; i < 12; ++i) {
            un += "1";
        }

        std::string result = calculateS(n, significand, un); // Calculate s

        std::cout << result << std::endl; // Output the result
    }

    return 0;
}