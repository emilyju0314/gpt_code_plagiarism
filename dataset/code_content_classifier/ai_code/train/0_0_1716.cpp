#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> evaluateExpression(const string& expression) {
    stack<char> operators;
    stack<int> operands;

    for (char c : expression) {
        if (c == '(' || c == '_' || c == '^') {
            operators.push(c);
        } else if (isdigit(c)) {
            operands.push(c - '0');
        } else if (c == ',') {
            continue;
        } else if (c == ')') {
            char op = operators.top();
            operators.pop();

            int val1 = operands.top();
            operands.pop();
            int val2 = operands.top();
            operands.pop();

            if (op == '_') {
                operands.push(min(val1, val2));
            } else if (op == '^') {
                operands.push(max(val1, val2));
            }
        } else if (c == '?') {
            break;
        }
    }

    return {operands.top(), operators.size() * 2};
}

int main() {
    int Q;
    cin >> Q;
    cin.ignore();

    vector<string> statements(Q);

    for (int i = 0; i < Q; i++) {
        getline(cin, statements[i]);
    }

    for (int i = 0; i < Q; i++) {
        pair<int, int> result = evaluateExpression(statements[i]);
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}