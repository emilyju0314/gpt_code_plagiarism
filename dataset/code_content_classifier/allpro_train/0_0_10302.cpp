#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool evaluateFormula(string formula) {
    stack<char> stk;
    
    for(int i = 0; i < formula.size(); i++) {
        if(formula[i] == ')') {
            char op = stk.top(); stk.pop();
            int count = 0;
            while(op != '(') {
                count++;
                op = stk.top(); stk.pop();
            }
            
            if(count == 1) {
                char operand2 = stk.top(); stk.pop();
                char operator1 = stk.top(); stk.pop();
                char operand1 = stk.top(); stk.pop();
                
                if(operand1 == 'T' && operand2 == 'T') {
                    if(operator1 == '*') stk.push('T');
                    else if(operator1 == '+') stk.push('T');
                    else if(operator1 == '-') stk.push('F');
                    else if(operator1 == '>') stk.push('T');
                } else if(operand1 == 'T' && operand2 == 'F') {
                    if(operator1 == '*') stk.push('F');
                    else if(operator1 == '+') stk.push('T');
                    else if(operator1 == '-') stk.push('T');
                    else if(operator1 == '>') stk.push('F');
                } else if(operand1 == 'F' && operand2 == 'T') {
                    if(operator1 == '*') stk.push('F');
                    else if(operator1 == '+') stk.push('T');
                    else if(operator1 == '-') stk.push('T');
                    else if(operator1 == '>') stk.push('T');
                } else if(operand1 == 'F' && operand2 == 'F') {
                    if(operator1 == '*') stk.push('F');
                    else if(operator1 == '+') stk.push('F');
                    else if(operator1 == '-') stk.push('T');
                    else if(operator1 == '>') stk.push('T');
                }
            } else {
                char operand = stk.top(); stk.pop();
                if(op == '-') {
                    if(operand == 'T') stk.push('F');
                    else if(operand == 'F') stk.push('T');
                }
            }
            
        } else {
            stk.push(formula[i]);
        }
    }
    
    return stk.top() == 'T';
}

int main() {
    string equation;
    
    while(getline(cin, equation) && equation != "#") {
        int equalSignPos = equation.find('=');
        string lhs = equation.substr(0, equalSignPos-1);
        string rhs = equation.substr(equalSignPos+2);
        
        if(evaluateFormula(lhs) == evaluateFormula(rhs)) {
            cout << "YES ";
        } else {
            cout << "NO ";
        }
    }
    
    return 0;
}