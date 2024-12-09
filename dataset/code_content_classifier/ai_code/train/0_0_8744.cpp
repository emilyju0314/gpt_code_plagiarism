#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int evaluateExpression(string exp) {
    stack<int> operands;
    istringstream iss(exp);
    string token;
    
    while (iss >> token) {
        if (token == "+") {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            operands.push(operand1 + operand2);
        } else if (token == "-") {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            operands.push(operand1 - operand2);
        } else if (token == "*") {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            operands.push(operand1 * operand2);
        } else {
            operands.push(stoi(token));
        }
    }
    
    return operands.top();
}

int main() {
    string exp;
    getline(cin, exp);
    
    cout << evaluateExpression(exp) << endl;
    
    return 0;
}