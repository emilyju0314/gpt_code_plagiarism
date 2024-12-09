#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    int datasets;
    cin >> datasets;

    for (int i = 0; i < datasets; i++) {
        int operatorGroups;
        cin >> operatorGroups;

        map<char, pair<char, int>> operatorMap;
        for (int j = 0; j < operatorGroups; j++) {
            char direction;
            int numOperators;
            cin >> direction >> numOperators;
            for (int k = 0; k < numOperators; k++) {
                char op;
                cin >> op;
                operatorMap[op] = make_pair(direction, j);
            }
        }

        int queries;
        cin >> queries;
        cin.ignore(); // ignore the newline character

        for (int j = 0; j < queries; j++) {
            string expression;
            getline(cin, expression);

            stack<pair<char, int>> operatorStack; // pair of operator and its group
            vector<string> output;

            for (char c: expression) {
                if (c == ' ') {
                    continue;
                }
                if (c == '(') {
                    operatorStack.push(make_pair(c, -1)); // -1 indicates no group
                } else if (c == ')') {
                    while (operatorStack.top().first != '(') {
                        output.push_back(string(1, operatorStack.top().first));
                        operatorStack.pop();
                    }
                    operatorStack.pop(); // pop the opening parenthesis
                } else if (operatorMap.find(c) != operatorMap.end()) {
                    while (!operatorStack.empty() && operatorStack.top().first != '(' &&
                           operatorMap[c].second >= operatorStack.top().second) {
                        output.push_back(string(1, operatorStack.top().first));
                        operatorStack.pop();
                    }
                    operatorStack.push(make_pair(c, operatorMap[c].second));
                } else {
                    output.push_back(string(1, c));
                }
            }

            while (!operatorStack.empty()) {
                output.push_back(string(1, operatorStack.top().first));
                operatorStack.pop();
            }

            for (string s: output) {
                cout << s;
            }
            cout << endl;
        }

        if (i < datasets - 1) {
            cout << endl;
        }
    }

    return 0;
}