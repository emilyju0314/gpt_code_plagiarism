#include <iostream>
#include <vector>
#include <cstring>

bool isValidOneStroke(const std::string& password) {
    int n = password.size();
    for (int i = 1; i < n; ++i) {
        if (password[i] == password[i-1]) {
            return false;
        }
        if (password[i] - 'A' == password[i-1] - 'A' + 1) {
            return false;
        }
        if (password[i-1] - 'A' == password[i] - 'A' + 1) {
            return false;
        }
        if (password[i] - 'A' == password[i-1] - 'A' + 2 && 
            password[i-1] - 'A' == password[i] - 'A' + 1) {
            return false;
        }
        if (password[i-1] - 'A' == password[i] - 'A' + 2 && 
            password[i] - 'A' == password[i-1] - 'A' + 1) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<std::string> passwords;
    for (int i = 0; i < 1000; ++i) {
        std::string password;
        std::cin >> password;
        if (isValidOneStroke(password)) {
            passwords.push_back(password);
        }
    }

    for (const auto& password : passwords) {
        std::cout << password << std::endl;
    }

    return 0;
}