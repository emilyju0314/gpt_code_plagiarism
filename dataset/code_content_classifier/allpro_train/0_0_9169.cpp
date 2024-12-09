#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool isBalanced(char open, char close) {
    return (open == '(' && close == ')');
}

int main() {
    string cmd;
    cin >> cmd;

    int count = 0;
    stack<int> stk;
    vector<int> res;

    for (char c : cmd) {
        if (c == '(') {
            stk.push(count);
        }
        else if (c == ')') {
            if (!stk.empty()) {
                res.push_back(count - stk.top() + 1);
                stk.pop();
            } else {
                res.push_back(0);
            }
        }
        else if (c == '-') {
            count--;
        }
        count++;
    }

    for (int val : res) {
        cout << val << endl;
    }

    return 0;
}