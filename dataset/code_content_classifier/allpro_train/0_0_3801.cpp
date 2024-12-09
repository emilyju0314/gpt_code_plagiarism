#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

struct Complex {
    int real;
    int imag;
};

Complex multiply(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}

Complex add(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

Complex subtract(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real - c2.real;
    result.imag = c1.imag - c2.imag;
    return result;
}

bool isOverflow(Complex c) {
    return (c.real > 10000 || c.imag > 10000 || c.real < -10000 || c.imag < -10000);
}

bool isNumeric(char c) {
    return (c >= '0' && c <= '9');
}

bool isSymbol(char c) {
    return (c == 'i' || c == '+' || c == '*' || c == '-');
}

Complex evaluateExpression(string expression) {
    vector<Complex> vals;
    vector<char> ops;

    int i = 0;
    bool isNegative = false;

    while (i < expression.length()) {
        if (isNumeric(expression[i])) {
            int num = 0;
            while (i < expression.length() && isNumeric(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            if (isNegative) {
                vals.push_back({-num, 0});
                isNegative = false;
            } else {
                vals.push_back({num, 0});
            }
        } else if (expression[i] == 'i') {
            if (isNegative) {
                vals.push_back({0, -1});
                isNegative = false;
            } else {
                vals.push_back({0, 1});
            }
            i++;
        } else if (expression[i] == '+') {
            ops.push_back('+');
            i++;
        } else if (expression[i] == '-') {
            if (i == 0 || !isNumeric(expression[i-1]) && expression[i-1] != 'i') {
                isNegative = true;
                i++;
            } else {
                ops.push_back('-');
                i++;
            }
        } else if (expression[i] == '*') {
            ops.push_back('*');
            i++;
        } else {
            i++;
        }
    }

    while (!ops.empty()) {
        char op = ops.back();
        ops.pop_back();
        Complex val1 = vals.back();
        vals.pop_back();
        Complex val2 = vals.back();
        vals.pop_back();

        if (op == '*') {
            Complex result = multiply(val1, val2);
            if (isOverflow(result)) {
                cout << "overflow" << endl;
                return {0, 0};
            } else {
                vals.push_back(result);
            }
        } else if (op == '+') {
            Complex result = add(val1, val2);
            if (isOverflow(result)) {
                cout << "overflow" << endl;
                return {0, 0};
            } else {
                vals.push_back(result);
            }
        } else if (op == '-') {
            Complex result = subtract(val1, val2);
            if (isOverflow(result)) {
                cout << "overflow" << endl;
                return {0, 0};
            } else {
                vals.push_back(result);
            }
        }
    }

    Complex finalResult = vals.back();

    if (finalResult.real == 0 && finalResult.imag == 0) {
        cout << 0 << endl;
    } else if (finalResult.real == 0) {
        cout << finalResult.imag << "i" << endl;
    } else if (finalResult.imag == 0) {
        cout << finalResult.real << endl;
    } else if (finalResult.imag < 0) {
        cout << finalResult.real << finalResult.imag << "i" << endl;
    } else {
        cout << finalResult.real << "+" << finalResult.imag << "i" << endl;
    }

    return finalResult;
}

int main() {
    string line;
    while(getline(cin, line)) {
        evaluateExpression(line);
    }
    return 0;
}