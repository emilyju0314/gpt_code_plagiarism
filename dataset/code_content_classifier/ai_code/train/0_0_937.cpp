#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int evaluateExpression(const vector<int>& operands, const vector<char>& operators) {
    int result = 0;
    char lastOperator = '+';
    for (int i = 0; i < operands.size(); i++) {
        if (lastOperator == '+') {
            result += operands[i];
        } else {
            result -= operands[i];
        }
        
        if (i < operators.size()) {
            lastOperator = operators[i];
        }
    }
    return result;
}

int main() {
    int N;
    cin >> N;

    vector<int> operands(N);
    vector<char> operators(N-1);

    for (int i = 0; i < N; i++) {
        cin >> operands[i];
        if (i < N-1) {
            cin >> operators[i];
        }
    }

    vector<int> positiveOperands;
    vector<int> negativeOperands;

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            positiveOperands.push_back(operands[i]);
        } else {
            negativeOperands.push_back(operands[i]);
        }
    }

    int maxEvaluatedValue = evaluateExpression(positiveOperands, vector<char>(positiveOperands.size()-1, '+'))
                            + evaluateExpression(negativeOperands, vector<char>(negativeOperands.size()-1, '+'));

    cout << maxEvaluatedValue << endl;

    return 0;
}