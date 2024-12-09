#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

int calculate(int a, int b, char op) {
    if(op == '^') {
        return a ^ b;
    } else if(op == '&') {
        return a & b;
    } else {
        return a | b;
    }
}

int main() {
    int N;
    cin >> N;
    
    string S;
    cin >> S;
    
    int Q;
    cin >> Q;
    
    for(int q = 0; q < Q; q++) {
        int i, j;
        cin >> i >> j;
        
        stack<int> num_stack;
        stack<char> op_stack;
        
        for(int k = i; k <= j; k++) {
            if(S[k] >= '0' && S[k] <= '9') {
                num_stack.push(S[k] - '0');
            } else {
                while(!op_stack.empty() && (op_stack.top() == '&' || (op_stack.top() == '^' && S[k] == '|'))) {
                    char op = op_stack.top();
                    op_stack.pop();
                    int b = num_stack.top();
                    num_stack.pop();
                    int a = num_stack.top();
                    num_stack.pop();
                    num_stack.push(calculate(a, b, op));
                }
                op_stack.push(S[k]);
            }
        }
        
        while(!op_stack.empty()) {
            char op = op_stack.top();
            op_stack.pop();
            int b = num_stack.top();
            num_stack.pop();
            int a = num_stack.top();
            num_stack.pop();
            num_stack.push(calculate(a, b, op));
        }
        
        cout << num_stack.top() << endl;
    }
    
    return 0;
}