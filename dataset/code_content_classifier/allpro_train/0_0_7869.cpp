#include <iostream>
#include <stack>
#include <string>

bool isBalanced(const std::string& str) {
    std::stack<char> s;
    for (char c : str) {
        if (c == '(' || c == '[') {
            s.push(c);
        } else if (c == ')' || c == ']') {
            if (s.empty()) {
                return false;
            } else if ((c == ')' && s.top() == '(') || (c == ']' && s.top() == '[')) {
                s.pop();
            } else {
                return false;
            }
        }
    }
    
    return s.empty();
}

int main() {
    std::string line;
    while (true) {
        std::getline(std::cin, line);
        if (line == ".") {
            break;
        }
        
        if (isBalanced(line)) {
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }
    
    return 0;
}