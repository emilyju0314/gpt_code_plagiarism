#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

double calculate(string formula) {
    stack<double> st;
    stringstream ss(formula);
    string token;
    
    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            double b = st.top();
            st.pop();
            double a = st.top();
            st.pop();
            
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") st.push(a / b);
        } else {
            st.push(stod(token));
        }
    }
    
    return st.top();
}

int main() {
    string formula;
    
    while (getline(cin, formula)) {
        cout << fixed << calculate(formula) << endl;
    }
    
    return 0;
}