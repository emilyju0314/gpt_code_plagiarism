#include <iostream>
#include <stack>

bool evaluateExpression(std::string& expression) {
    std::stack<char> st;
    
    for(char c : expression) {
        if(c == '(') {
            st.push(c);
        } else if(c == '|') {
            st.push(c);
        } else if(c == ')') {
            char top = st.top();
            st.pop();
            
            if(top == '|') {
                char prevTop = st.top();
                st.pop();
                
                if(st.top() == '(') {
                    return true; // If there is a clause that is true, return true
                }
                st.push(prevTop);
            }
            st.pop(); // Pop the opening parenthesis
        }
    }
    
    return false; // If no clause evaluates to true, return false
}

int main() {
    std::string expression;
    
    while(true) {
        std::getline(std::cin, expression);
        if(expression == "#") {
            break;
        }
        
        if(evaluateExpression(expression)) {
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }
    
    return 0;
}