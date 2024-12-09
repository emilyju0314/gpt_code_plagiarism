#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>

std::string trim(const std::string &str) {
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::vector<std::string> lines;
    std::string line;
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, line);
        lines.push_back(trim(line));
    }

    std::string exceptionType;
    for (int i = 0; i < n; ++i) {
        if (lines[i].find("throw") != std::string::npos) {
            std::stringstream ss(lines[i]);
            std::string temp;
            ss >> temp >> temp >> exceptionType;
            break;
        }
    }

    std::stack<std::pair<std::string, std::string>> tryCatchBlocks;
    for (int i = 0; i < n; ++i) {
        if (lines[i].find("try") != std::string::npos) {
            tryCatchBlocks.push(std::make_pair("", ""));
        } else if (lines[i].find("catch") != std::string::npos) {
            std::string token, exception, message;
            std::stringstream ss(lines[i]);
            ss >> token >> token;

            ss >> exception;
            exception = exception.substr(1, exception.size() - 2);

            ss >> message;
            message = message.substr(1, message.size() - 2);

            tryCatchBlocks.top() = std::make_pair(exception, message);
        }
    }

    while (!tryCatchBlocks.empty()) {
        if (tryCatchBlocks.top().first == exceptionType) {
            std::cout << tryCatchBlocks.top().second << std::endl;
            return 0;
        }
        tryCatchBlocks.pop();
    }

    std::cout << "Unhandled Exception" << std::endl;

    return 0;
}