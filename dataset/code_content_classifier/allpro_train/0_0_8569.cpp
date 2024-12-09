#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // ignore the newline character
    
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        
        stack<char> st;
        bool valid = true;
        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else {
                if (st.empty() || st.top() != '(') {
                    valid = false;
                    break;
                }
                st.pop();
            }
        }
        
        if (st.empty() && valid) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}