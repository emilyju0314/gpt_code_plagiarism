#include <iostream>
#include <string>
#include <stack>

int evaluateExpr(std::string expr) {
    std::stack<int> nums;
    int sign = 1;
    int result = 0;

    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(') {
            nums.push(result);
            nums.push(sign);
            result = 0;
            sign = 1;
        } else if (expr[i] == ')') {
            result *= nums.top();
            nums.pop();
            result += nums.top();
            nums.pop();
        } else if (expr[i] == '+') {
            sign = 1;
        } else if (expr[i] == '-') {
            sign = -1;
        } else if (isdigit(expr[i])) {
            int num = expr[i] - '0';
            result += sign * num;
        }
    }

    return result;
}

int getMaximumNumber(std::string S) {
    int maxNumber = INT_MIN;

    for (int i=0; i<S.length(); i++) {
        if (S[i] == '+' || S[i] == '-') {
            std::string expr = S.substr(0, i) + '(' + S.substr(i) + ')';
            int result = evaluateExpr(expr);
            maxNumber = std::max(maxNumber, result);
        }
    }

    return maxNumber;
}

int main() {
    std::string S;
    std::cin >> S;

    int maximumNumber = getMaximumNumber(S);

    std::cout << maximumNumber << std::endl;

    return 0;
}