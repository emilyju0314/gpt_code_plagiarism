#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

string errtype = "errtype";
unordered_map<string, string> typedefs;

string dereference(string type) {
    while(type.size() > 1 && type.back() == '*') {
        type.pop_back();
        if (type.back() == '&') type = errtype;
    }
    return type;
}

int main() {
    int n;
    cin >> n;
    
    stack<string> oper_stack;
    
    for (int i = 0; i < n; i++) {
        string operation, A, B;
        cin >> operation >> A;
        
        if (operation == "typedef") {
            cin >> B;
            string base_type = dereference(A);
            typedefs[B] = base_type;
        } else if (operation == "typeof") {
            string base_type = dereference(A);
            string result = base_type;
            for (char c : A) {
                if (c == '*') result += "*";
                else if (c == '&') result = "&" + result;
            }
            while (!oper_stack.empty()) {
                string top = oper_stack.top();
                if (typedefs.find(top) != typedefs.end()) {
                    string new_base = dereference(typedefs[top]);
                    result = new_base + result.substr(top.size());
                    oper_stack.pop();
                } else {
                    break;
                }
            }
            cout << result << endl;
            if (result != errtype) oper_stack.push(result);
        }
    }

    return 0;
}