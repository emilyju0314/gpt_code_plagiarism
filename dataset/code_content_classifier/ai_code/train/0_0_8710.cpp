#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

bool isSuspicious(string expression, unordered_map<string, string>& macros) {
    stack<char> st;
    for(char c : expression) {
        if(c == '(' || c == '+' || c == '-' || c == '*' || c == '/') {
            st.push(c);
        } else if(c == ')') {
            char top = st.top();
            st.pop();

            if(top != '(') {
                return true;
            }

            if(st.size() >= 2) {
                char op = st.top();
                st.pop();
                char prev = st.top();
                if(op == '+' || op == '-') {
                    if(prev == '*' || prev == '/') {
                        return false;
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    unordered_map<string, string> macros;

    for(int i = 0; i < n; i++) {
        string define, name, val;
        cin >> define >> name >> val;
        macros[name] = val;
    }

    string expression;
    getline(cin >> ws, expression); // read expression ignoring leading whitespace

    string subst_expr = expression;
    for(auto& pair : macros) {
        size_t pos = 0;
        while((pos = subst_expr.find(pair.first, pos)) != string::npos) {
            subst_expr.replace(pos, pair.first.length(), pair.second);
            pos += pair.second.length();
        }
    }

    if(isSuspicious(subst_expr, macros)) {
        cout << "Suspicious" << endl;
    } else {
        cout << "OK" << endl;
    }

    return 0;
}