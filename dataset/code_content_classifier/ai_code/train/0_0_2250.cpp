#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int calculate(const string& expression) {
    stack<int> operands;
    stack<char> operators;

    for (char c : expression) {
        if (isdigit(c)) {
            operands.push(c - '0');
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (operators.top() != '(') {
                char op = operators.top();
                operators.pop();
                int operand2 = operands.top();
                operands.pop();
                int operand1 = operands.top();
                operands.pop();
                if (op == '*') {
                    operands.push(operand1 * operand2);
                } else if (op == '+') {
                    operands.push(operand1 + operand2);
                } else if (op == '-') {
                    operands.push(operand1 - operand2);
                } else if (op == '&') {
                    operands.push(operand1 & operand2);
                } else if (op == '^') {
                    operands.push(operand1 ^ operand2);
                } else if (op == '|') {
                    operands.push(operand1 | operand2);
                }
            }
            operators.pop();
        } else {
            while (!operators.empty() && operators.top() != '(' && (c == '*' || c == '|' || (c == '+' || c == '-') || (c == '&' || (c == '^')))) {
                char op = operators.top();
                operators.pop();
                int operand2 = operands.top();
                operands.pop();
                int operand1 = operands.top();
                operands.pop();
                if (op == '*') {
                    operands.push(operand1 * operand2);
                } else if (op == '+') {
                    operands.push(operand1 + operand2);
                } else if (op == '-') {
                    operands.push(operand1 - operand2);
                } else if (op == '&') {
                    operands.push(operand1 & operand2);
                } else if (op == '^') {
                    operands.push(operand1 ^ operand2);
                } else if (op == '|') {
                    operands.push(operand1 | operand2);
                }
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();
        int operand2 = operands.top();
        operands.pop();
        int operand1 = operands.top();
        operands.pop();
        if (op == '*') {
            operands.push(operand1 * operand2);
        } else if (op == '+') {
            operands.push(operand1 + operand2);
        } else if (op == '-') {
            operands.push(operand1 - operand2);
        } else if (op == '&') {
            operands.push(operand1 & operand2);
        } else if (op == '^') {
            operands.push(operand1 ^ operand2);
        } else if (op == '|') {
            operands.push(operand1 | operand2);
        }
    }

    return operands.top();
}

int main() {
    int N;
    string expression;
    vector<pair<int, string>> datasets;

    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }
        cin.ignore();
        getline(cin, expression);
        datasets.push_back({N, expression});
    }

    for (auto dataset : datasets) {
        string expression = dataset.second;
        for (int i = 0; i < dataset.first; i++) {
            // Ono no Komachi minimizes the result
            if (i % 2 == 0) {
                size_t pos = expression.find_first_of("0123456789");
                while (pos != string::npos) {
                    expression.replace(pos, 1, "0");
                    pos = expression.find_first_of("0123456789", pos + 1);
                }
            } else {
                size_t pos = expression.find_first_of("0123456789");
                while (pos != string::npos) {
                    expression.replace(pos, 1, "9");
                    pos = expression.find_first_of("0123456789", pos + 1);
                }
            }
        }
        cout << calculate(expression) << endl;
    }

    return 0;
}