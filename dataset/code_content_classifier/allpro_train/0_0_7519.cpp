#include <iostream>
#include <string>

struct Node {
    char val;
    Node* left;
    Node* right;

    Node(char v) : val(v), left(nullptr), right(nullptr) {}
};

std::string parseTreeExpression(std::string& expression, int& index) {
    if (expression[index] == '(') {
        index++; // skip '('
        std::string result = "(";
        if (expression[index] == ',') {
            result += ",";
            index++; // skip ','
        } else {
            result += parseTreeExpression(expression, index);
        }
        index++; // skip ','
        if (expression[index] == ',') {
            result += ",";
            index++; // skip ','
        } else {
            result += parseTreeExpression(expression, index);
        }
        index++; // skip ')'
        return result + ")";
    } else {
        return "";
    }
}

std::string mergeTrees(Node* tree1, Node* tree2, char op) {
    if (tree1 == nullptr || tree2 == nullptr) {
        return "";
    }

    std::string result = "(";
    if (op == 'i' && (tree1->val == '1' && tree2->val == '2')) || (op == 'u' && (tree1->val == '1' || tree2->val == '2')) {
        result += tree1->val;
        if (tree1->left || tree2->left) {
            result += mergeTrees(tree1->left, tree2->left, op);
        }
        if (tree1->right || tree2->right) {
            result += mergeTrees(tree1->right, tree2->right, op);
        }
    }
    return result + ")";
}

int main() {
    char op;
    std::string tree1_expression, tree2_expression;

    while (std::cin >> op >> tree1_expression >> tree2_expression) {
        int index = 0;
        std::string tree1_parsed = parseTreeExpression(tree1_expression, index);
        index = 0;
        std::string tree2_parsed = parseTreeExpression(tree2_expression, index);

        Node* tree1 = new Node(tree1_parsed[1]);
        Node* tree2 = new Node(tree2_parsed[1]);

        std::string result = mergeTrees(tree1, tree2, op);
        std::cout << result << std::endl;
    }

    return 0;
}