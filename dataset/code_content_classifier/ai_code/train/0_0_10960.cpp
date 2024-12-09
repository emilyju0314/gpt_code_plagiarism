#include <iostream>
#include <string>
#include <vector>

const int MOD = 1000000007;

struct Node {
    char op;
    int val;
    Node *left;
    Node *right;
    
    Node(char op, int val) : op(op), val(val), left(nullptr), right(nullptr) {}
};

Node* parseExpression(const std::string& s, int& pos) {
    if (s[pos] == '(') {
        pos++; // Skip '('
        Node* left = parseExpression(s, pos);
        
        char op = s[pos];
        pos++; // Consume operator
        
        Node* right = parseExpression(s, pos);
        
        pos++; // Skip ')'
        
        Node* current = new Node(op, 0);
        current->left = left;
        current->right = right;
        
        return current;
    } else {
        int val = 0;
        while (isdigit(s[pos])) {
            val = (val * 10 + (s[pos] - '0')) % MOD;
            pos++;
        }
        
        return new Node('0', val);
    }
}

int evaluateExpression(Node* root) {
    if (!root) return -1;
    
    if (root->op == '0') {
        return root->val;
    } else {
        int leftVal = evaluateExpression(root->left) % MOD;
        int rightVal = evaluateExpression(root->right) % MOD;
        
        if (root->op == '+') return (leftVal + rightVal) % MOD;
        else if (root->op == '*') return (leftVal * rightVal) % MOD;
    }
    
    return -1;
}

int main() {
    std::string expression;
    std::cin >> expression;
    
    int numQueries;
    std::cin >> numQueries;
    
    Node* root = parseExpression(expression, 0);
    
    for (int i = 0; i < numQueries; i++) {
        int left, right;
        std::cin >> left >> right;
        
        // Find sub-expression by traversing the tree
        Node* current = root;
        int j = 1;
        while (true) {
            if (j >= left && j <= right) {
                int result = evaluateExpression(current);
                if (result != -1) {
                    std::cout << result << std::endl;
                } else {
                    std::cout << -1 << std::endl;
                }
                break;
            } else {
                j++;
                if (current->left) {
                    current = current->left;
                } else {
                    break;
                }
            }
        }
    }
    
    return 0;
}