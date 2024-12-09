#include <iostream>
#include <vector>
#include <string>
#include <sstream>

struct BUT {
    char label;
    BUT* left;
    BUT* right;

    BUT(char l) : label(l), left(nullptr), right(nullptr) {}
};

void parseExpression(std::string expression) {
    std::vector<BUT*> stack;
    BUT* root = nullptr;
    BUT* current = nullptr;

    for (char c : expression) {
        if (c == '(') {
            continue;
        } else if (std::isalpha(c)) {
            current = new BUT(c);
            if (!root) {
                root = current;
            } else {
                if (stack.back()->left == nullptr) {
                    stack.back()->left = current;
                } else {
                    stack.back()->right = current;
                }
            }
        } else if (c == ',') {
            stack.push_back(current);
        } else if (c == ')') {
            if (!stack.empty()) {
                stack.pop_back();
            }
        }
    }

    // Print the diagram
    static int count = 1;
    std::cout << count++ << ":" << std::endl;
    std::function<void(BUT*, int)> printDiagram = [&](BUT* node, int depth) {
        if (node) {
            printDiagram(node->right, depth+1);
            for (int i = 0; i < depth; i++) {
                std::cout << " ";
            }
            std::cout << node->label << std::endl;
            for (int i = 0; i < depth; i++) {
                std::cout << " ";
            }
            std::cout << "---" << std::endl;
            printDiagram(node->left, depth+1);
        }
    };

    printDiagram(root, 0);
    std::cout << std::endl;
}

int main() {
    std::string expression;
    std::string input;
    while (getline(std::cin, input) && input != ".") {
        expression += input;
    }
    
    std::stringstream ss(expression);
    std::string subexpression;
    while (getline(ss, subexpression, ';')) {
        parseExpression(subexpression);
    }
    
    return 0;
}