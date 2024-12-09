#include <iostream>
#include <stack>
#include <string>

int main() {
    std::string wires;
    std::cin >> wires;
    
    // Use a stack to keep track of the order in which the wires run above each other
    std::stack<char> s;
    
    for (char wire : wires) {
        if (s.empty() || s.top() != wire) {
            s.push(wire);
        } else {
            s.pop();
        }
    }
    
    // If the stack is empty, the wires can be untangled
    if (s.empty()) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    
    return 0;
}