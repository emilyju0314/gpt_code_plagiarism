#include <iostream>
#include <stack>
#include <string>

bool isDeterminable(int n, const std::string& formula) {
    std::stack<char> stack;
    
    for (char c : formula) {
        if (c == '(') {
            stack.push('(');
        } else if (c == '?') {
            stack.push('?');
        } else if (c == '|' || c == '&' || c == '^') {
            if (stack.empty() || stack.top() != '?') {
                return false;
            }
        } else if (c == ')') {
            char operation = stack.top();
            stack.pop();
            stack.pop();
            if (stack.empty() || stack.top() != '?') {
                stack.push(operation);
            }
        }
    }
    
    return stack.size() == 0 || (n % 2 == 1);
}

int main() {
    int n;
    std::string formula;
    
    std::cin >> n;
    std::cin >> formula;
    
    if (isDeterminable(n, formula)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}