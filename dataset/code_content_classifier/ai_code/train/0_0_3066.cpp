#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string feedGolorp(const std::string& name) {
    std::vector<int> variables;

    for (char c : name) {
        if (c >= '0' && c <= '9') {
            variables.push_back(c - '0');
        }
    }

    if (variables.size() % 5 != 0) {
        return "false";
    }

    std::sort(variables.begin(), variables.end());

    std::string result;
    for (int i = 0; i < variables.size(); ++i) {
        result += std::to_string(variables[i]);
    }

    return result;
}

int main() {
    std::string name;
    std::cin >> name;

    std::string sequence = feedGolorp(name);
    std::cout << sequence << std::endl;

    return 0;
}