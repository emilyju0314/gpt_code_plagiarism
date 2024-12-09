#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int evalExpression(string expr, int start, int end) {
    if (expr[start] == '(' && expr[end] == ')') {
        return evalExpression(expr, start + 1, end - 1);
    } else {
        int count = 0;
        for (int i = start; i <= end; i++) {
            if (expr[i] == '|') {
                count += (evalExpression(expr, start, i - 1) * evalExpression(expr, i + 1, end)) % MOD;
            } else if (expr[i] == '&') {
                count += (evalExpression(expr, start, i - 1) * evalExpression(expr, i + 1, end)) % MOD;
            }
        }
        return count % MOD;
    }
}

int main() {
    string expr;
    cin >> expr;

    int result = evalExpression(expr, 0, expr.length() - 1);
    cout << result << endl;

    return 0;
}