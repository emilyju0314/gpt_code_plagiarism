#include <iostream>
#include <string>
#include <vector>

bool isValidFileName(const std::string& fileName) {
    size_t dotPos = fileName.find('.');
    if (dotPos == std::string::npos) {
        return false;
    }
    std::string name = fileName.substr(0, dotPos);
    std::string ext = fileName.substr(dotPos + 1);
    if (name.length() > 8 || name.length() == 0 || ext.length() > 3 || ext.length() == 0) {
        return false;
    }
    for (char c : name) {
        if (!islower(c)) {
            return false;
        }
    }
    for (char c : ext) {
        if (!islower(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string s;
    std::cin >> s;

    std::vector<std::string> parts;
    std::string currentFileName = "";
    for (char c : s) {
        if (islower(c) || c == '.') {
            currentFileName += c;
            if (isValidFileName(currentFileName)) {
                parts.push_back(currentFileName);
                currentFileName = "";
            }
        } else {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    if (currentFileName != "") {
        parts.push_back(currentFileName);
    }

    std::cout << "YES" << std::endl;
    for (const std::string& part : parts) {
        std::cout << part << std::endl;
    }

    return 0;
}