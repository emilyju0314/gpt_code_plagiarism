#include <iostream>
#include <string>
#include <stack>

using namespace std;

int calculateShortestLength(string expression) {
    stack<char> st;
    
    for(char c : expression) {
        if(c == ')') {
            string temp = "";
            while(st.top() != '(') {
                temp += st.top();
                st.pop();
            }
            st.pop();
            if(temp.length() == 3 && temp[1] == '^' && temp[0] == temp[2]) {
                st.push('0');
            } else if(temp.length() == 3 && temp[1] == '*' && (temp[0] == '0' || temp[2] == '0')) {
                st.push('0');
            } else {
                st.push('(');
                for(char ch : temp) {
                    st.push(ch);
                }
                st.push(')');
            }
        } else {
            st.push(c);
        }
    }
    
    return st.size() - 1;
}

int main() {
    string expression;
    
    while(true) {
        cin >> expression;
        if(expression == ".") {
            break;
        }
        
        cout << calculateShortestLength(expression) << endl;
    }
    
    return 0;
}