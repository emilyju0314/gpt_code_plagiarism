#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int calc(int a, int b, int c, int d, char op1, char op2, char op3) {
    int result = 0;
    if(op1 == '+') {
        result = a + b;
    } else if(op1 == '-') {
        result = a - b;
    } else {
        result = a * b;
    }

    if(op2 == '+') {
        result = result + c;
    } else if(op2 == '-') {
        result = result - c;
    } else {
        result = result * c;
    }

    if(op3 == '+') {
        result = result + d;
    } else if(op3 == '-') {
        result = result - d;
    } else {
        result = result * d;
    }

    return result;
}

string createExpression(int a, int b, int c, int d) {
    vector<char> ops = {'+', '-', '*'};
    sort(ops.begin(), ops.end());

    do {
        for(char op1 : ops) {
            for(char op2 : ops) {
                for(char op3 : ops) {
                    if(calc(a, b, c, d, op1, op2, op3) == 10) {
                        string expression = "("+to_string(a)+" "+op1+" "+to_string(b)+") "+op2+" ("+to_string(c)+" "+op3+" "+to_string(d)+")";
                        return expression;
                    }
                }
            }
        }
    } while(next_permutation(ops.begin(), ops.end()));

    return "0";
}

int main() {
    int a, b, c, d;
    
    while(true) {
        cin >> a >> b >> c >> d;
        if(a == 0 && b == 0 && c == 0 && d == 0) {
            break;
        }

        string expression = createExpression(a, b, c, d);
        cout << expression << endl;
    }

    return 0;
}