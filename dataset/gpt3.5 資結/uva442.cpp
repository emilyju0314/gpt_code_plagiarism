#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

struct Matrix {
    int rows, cols;
};

int main() {
    int n;
    cin >> n;

    map<char, Matrix> matrices;
    stack<Matrix> stk;

    for (int i = 0; i < n; i++) {
        char name;
        cin >> name;

        Matrix m;
        cin >> m.rows >> m.cols;

        matrices[name] = m;
    }

    string expression;
    cin >> expression;

    int result = 0;
    bool error = false;

    for (char c : expression) {
        if (c == '(') {
            stk.push(Matrix{ 0, 0 });
        }
        else if (isalpha(c)) {
            stk.push(matrices[c]);
        }
        else if (c == ')') {
            Matrix m2 = stk.top();
            stk.pop();
            Matrix m1 = stk.top();
            stk.pop();

            if (m1.cols != m2.rows) {
                error = true;
                break;
            }

            result += m1.rows * m1.cols * m2.cols;

            stk.push(Matrix{ m1.rows, m2.cols });
        }
    }

    if (error) {
        cout << "error" << endl;
    }
    else {
        cout << result << endl;
    }

    return 0;
}