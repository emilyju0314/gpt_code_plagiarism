#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> words(n);
    for (int i = 0; i < n; i++) {
        std::cin >> words[i];
    }

    std::string message;
    std::cin >> message;

    std::string coded_message;
    for (int i = 0; i < n; i++) {
        coded_message += "<3" + words[i];
    }
    coded_message += "<3";

    int index = 0;
    for (char c : message) {
        if (index >= coded_message.length()) {
            break;
        }
        if (c == coded_message[index]) {
            index++;
        }
    }

    if (index == coded_message.length()) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    return 0;
}  