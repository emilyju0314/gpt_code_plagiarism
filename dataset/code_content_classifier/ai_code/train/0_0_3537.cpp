#include <iostream>
#include <string>
#include <stack>

using namespace std;

int mod(int a, int p) {
    return (a % p + p) % p;
}

int power(int a, int b, int p) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = mod(res * a, p);
        }
        a = mod(a * a, p);
        b /= 2;
    }
    return res;
}

int calculate(string expression, int p) {
    stack<int> nums;
    stack<char> ops;

    for (int i = 0; i < expression.size(); i++) {
        if (isdigit(expression[i])) {
            int num = 0;
            while (i < expression.size() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            nums.push(num);
        } else if (expression[i] == '(') {
            ops.push(expression[i]);
        } else if (expression[i] == ')') {
            while (ops.top() != '(') {
                int num2 = nums.top(); nums.pop();
                int num1 = nums.top(); nums.pop();
                char op = ops.top(); ops.pop();
                if (op == '+') {
                    nums.push(mod(num1 + num2, p));
                } else if (op == '-') {
                    nums.push(mod(num1 - num2, p));
                } else if (op == '*') {
                    nums.push(mod(num1 * num2, p));
                } else if (op == '/') {
                    nums.push(mod(num1 * power(num2, p - 2, p), p));
                }
            }
            ops.pop();
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (!ops.empty() && (ops.top() == '*' || ops.top() == '/') && ops.top() != '(') {
                int num2 = nums.top(); nums.pop();
                int num1 = nums.top(); nums.pop();
                char op = ops.top(); ops.pop();
                if (op == '*') {
                    nums.push(mod(num1 * num2, p));
                } else if (op == '/') {
                    nums.push(mod(num1 * power(num2, p - 2, p), p));
                }
            }
            ops.push(expression[i]);
        }
    }

    while (!ops.empty()) {
        int num2 = nums.top(); nums.pop();
        int num1 = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();
        if (op == '+') {
            nums.push(mod(num1 + num2, p));
        } else if (op == '-') {
            nums.push(mod(num1 - num2, p));
        } else if (op == '*') {
            nums.push(mod(num1 * num2, p));
        } else if (op == '/') {
            nums.push(mod(num1 * power(num2, p - 2, p), p));
        }
    }

    return nums.top();
}

int main() {
    string input;
    while (getline(cin, input) && input != "0:") {
        int p;
        string expression;
        sscanf(input.c_str(), "%d: %[^\n]", &p, &expression[0]);

        int result = calculate(expression, p);
        if (result == -1) {
            cout << "NG" << endl;
        } else {
            cout << expression << " = " << result << " (mod " << p << ")" << endl;
        }
    }

    return 0;
}