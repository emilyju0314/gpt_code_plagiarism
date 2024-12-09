#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;

    // Reverse the string
    std::string reversedStr = "";
    for (int i = str.length() - 1; i >= 0; i--) {
        reversedStr += str[i];
    }

    // Print the reversed string
    std::cout << reversedStr << std::endl;

    return 0;
}