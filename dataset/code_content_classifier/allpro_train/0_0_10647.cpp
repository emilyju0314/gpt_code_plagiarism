#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

int evaluateShipuraExpression(const string& expr) {
    stack<int> numbers;
    stack<char> operators;

    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == ' ') {
            continue;
        } else if (expr[i] == 'S') {
            operators.push('S');
        } else if (expr[i] == '<') {
            operators.push('<');
        } else if (isdigit(expr[i])) {
            int number = 0;
            while (isdigit(expr[i])) {
                number = number * 10 + (expr[i] - '0');
                i++;
            }
            i--;
            if (!operators.empty() && operators.top() == 'S') {
                numbers.push((int)pow(number, 2) % 1000000007);
                operators.pop();
            } else {
                numbers.push(number);
            }
        } else if (expr[i] == '>') {
            while (!operators.empty() && operators.top() == 'S') {
                int num = numbers.top();
                numbers.pop();
                numbers.push((int)pow(num, 2) % 1000000007);
                operators.pop();
            }
            operators.pop();
        } else if (expr[i] == '>') {
            while (!operators.empty() && operators.top() == '>') {
                int num2 = numbers.top();
                numbers.pop();
                int num1 = numbers.top();
                numbers.pop();
                numbers.push(num1 >> num2);
                operators.pop();
            }
            operators.push('>');
        }
    }

    while (!operators.empty()) {
        int num2 = numbers.top();
        numbers.pop();
        int num1 = numbers.top();
        numbers.pop();
        numbers.push(num1 >> num2);
        operators.pop();
    }

    return numbers.top();
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line == "#") {
            break;
        }
        cout << evaluateShipuraExpression(line) << endl;
    }

    return 0;
}