#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

long long calculate(char op, long long a, long long b) {
    if(op == '+') {
        return a + b;
    } else if(op == '-') {
        return a - b;
    } else {
        return a * b;
    }
}

long long evaluate(const vector<char>& formula, const vector<char>& priority) {
    stack<long long> nums;
    stack<char> ops;

    for(char c : formula) {
        if(isdigit(c)) {
            nums.push(c - '0');
        } else if(c == '(') {
            ops.push(c);
        } else if(c == ')') {
            while(ops.top() != '(') {
                long long b = nums.top(); nums.pop();
                long long a = nums.top(); nums.pop();
                char op = ops.top(); ops.pop();
                nums.push(calculate(op, a, b));
            }
            ops.pop();
        } else {
            while(!ops.empty() && priority[ops.top()] >= priority[c]) {
                long long b = nums.top(); nums.pop();
                long long a = nums.top(); nums.pop();
                char op = ops.top(); ops.pop();
                nums.push(calculate(op, a, b));
            }
            ops.push(c);
        }
    }

    while(!ops.empty()) {
        long long b = nums.top(); nums.pop();
        long long a = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();
        nums.push(calculate(op, a, b));
    }

    return nums.top();
}

int main() {
    string input;
    cin >> input;

    vector<char> formula;
    vector<char> priority = {
        ['+'] = 0,
        ['-'] = 0,
        ['*'] = 0
    };

    for(char c : input) {
        if(c == '+' || c == '-' || c == '*') {
            formula.push_back(c);
            priority[c]++;
        } else {
            formula.push_back(c);
        }
    }

    long long max_answer = 0;

    vector<char> perm = {'+', '-', '*'};

    do {
        long long answer = evaluate(formula, priority);
        max_answer = max(max_answer, answer);
    } while(next_permutation(perm.begin(), perm.end()));

    cout << max_answer << endl;

    return 0;
}