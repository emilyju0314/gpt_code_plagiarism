#include <iostream>
#include <string>
#include <regex>

bool isValidJabberID(const std::string& jabberID) {
    std::regex pattern("^[a-zA-Z0-9_]{1,16}@[a-zA-Z0-9_]{1,16}(\\.[a-zA-Z0-9_]{1,16}){0,2}(\\/[a-zA-Z0-9_]{1,16})?$");
    return std::regex_match(jabberID, pattern);
}

int main() {
    std::string jabberID;
    std::getline(std::cin, jabberID);

    if (isValidJabberID(jabberID)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}