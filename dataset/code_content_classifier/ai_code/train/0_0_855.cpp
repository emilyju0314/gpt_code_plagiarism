#include <iostream>
#include <string>
#include <stack>

using namespace std;

int evaluate(char op, int x, int y){
    if(op == '*'){
        return x*y;
    } else if(op == '+'){
        return max(x, y);
    } else {
        return -1; // Error case
    }
}

int main() {
    string formula;
    
    while(getline(cin, formula)){
        if(formula == ".") break;
        
        stack<char> operators;
        stack<int> values;
        
        for(char c : formula){
            if(c == '('){
                continue;
            } else if(c == ')'){
                char op = operators.top();
                operators.pop();
                
                int y = values.top();
                values.pop();
                
                int x = values.top();
                values.pop();
                
                values.push(evaluate(op, x, y));
            } else if(c == '-' || c == '*' || c == '+'){
                operators.push(c);
            } else {
                if(c == 'P'){
                    values.push(2);
                } else if(c == 'Q'){
                    values.push(2);
                } else if(c == 'R'){
                    values.push(2);
                } else {
                    values.push(c - '0'); // Convert char to int
                }
            }
        }
        
        cout << values.top() << endl;
    }
    
    return 0;
}