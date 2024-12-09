#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

int calculate(string expression) {
    stack<int> numStack;
    stack<char> opStack;

    for (int i = 0; i < expression.length(); i++) {
        if (isdigit(expression[i])) {
            int num = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            numStack.push(num);
            i--;
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (!opStack.empty() && (opStack.top() == '*' || opStack.top() == '/')) {
                int num2 = numStack.top();
                numStack.pop();
                int num1 = numStack.top();
                numStack.pop();
                if (opStack.top() == '*') {
                    numStack.push(num1 * num2);
                } else {
                    numStack.push(num1 / num2);
                }
                opStack.pop();
            }
            opStack.push(expression[i]);
        } else if (expression[i] == '(') {
            opStack.push(expression[i]);
        } else if (expression[i] == ')') {
            while (opStack.top() != '(') {
                int num2 = numStack.top();
                numStack.pop();
                int num1 = numStack.top();
                numStack.pop();
                if (opStack.top() == '+') {
                    numStack.push(num1 + num2);
                } else if (opStack.top() == '-') {
                    numStack.push(num1 - num2);
                } else if (opStack.top() == '*') {
                    numStack.push(num1 * num2);
                } else {
                    numStack.push(num1 / num2);
                }
                opStack.pop();
            }
            opStack.pop();
        }
    }

    while (!opStack.empty()) {
        int num2 = numStack.top();
        numStack.pop();
        int num1 = numStack.top();
        numStack.pop();
        if (opStack.top() == '+') {
            numStack.push(num1 + num2);
        } else if (opStack.top() == '-') {
            numStack.push(num1 - num2);
        } else if (opStack.top() == '*') {
            numStack.push(num1 * num2);
        } else {
            numStack.push(num1 / num2);
        }
        opStack.pop();
    }

    return numStack.top();
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string expression;
        getline(cin, expression);
        cout << calculate(expression) << endl;
    }

    return 0;
}