#include <iostream>
#include <string>
#include <vector>

std::string parseSExpression(std::string& input) {
    std::string output;
    std::vector<std::string> elements;
    std::string element;

    for (char c : input) {
        if (c == '(' || c == ')' || c == ',' || c == ' ') {
            if (!element.empty()) {
                elements.push_back(element);
                element.clear();
            }
        } else {
            element += c;
        }
    }

    if (elements.size() == 1) {
        output = "a list of " + elements[0];
    } else {
        output = "a list of ";
        for (int i = 0; i < elements.size(); i++) {
            if (i == elements.size() - 1) {
                output += "and " + elements[i];
            } else {
                output += elements[i] + ", ";
            }
        }
    }

    return output;
}

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();

    for (int i = 0; i < N; i++) {
        std::string input;
        std::getline(std::cin, input);

        std::string result = parseSExpression(input);
        std::cout << result << std::endl;
    }

    return 0;
}