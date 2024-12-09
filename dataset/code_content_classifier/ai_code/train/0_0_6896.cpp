#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string encryptedPassword;
    std::string binaryCode;
    std::unordered_map<std::string, char> binaryToDigit;

    // Input binary code and corresponding binary codes for digits
    std::cin >> encryptedPassword;
    for (int i = 0; i < 10; i++) {
        std::string code;
        std::cin >> code;
        binaryToDigit[code] = '0' + i;
    }

    // Decrypt the password
    std::string password;
    for (int i = 0; i < encryptedPassword.length(); i += 10) {
        std::string substring = encryptedPassword.substr(i, 10);
        password += binaryToDigit[substring];
    }

    // Output the decrypted password
    std::cout << password << std::endl;

    return 0;
}