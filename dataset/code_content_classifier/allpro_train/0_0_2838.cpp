#include <iostream>
#include <string>
#include <algorithm>

std::string decryptCaesarCipher(std::string text) {
    std::string decryptedText = text;
    for (int shift = 1; shift < 26; shift++) {
        for (char &c : decryptedText) {
            if (isalpha(c)) {
                c = ((c - 'a' - shift + 26) % 26) + 'a';
            }
        }
        if (decryptedText.find("the") != std::string::npos ||
            decryptedText.find("this") != std::string::npos ||
            decryptedText.find("that") != std::string::npos) {
            break;
        }
    }
    return decryptedText;
}

int main() {
    std::string encryptedText;
    while (std::getline(std::cin, encryptedText)) {
        std::string decryptedText = decryptCaesarCipher(encryptedText);
        std::cout << decryptedText << std::endl;
    }
    
    return 0;
}