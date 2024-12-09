#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    string brackets;
    cin >> brackets;

    stack<char> st;
    int max_len = 0;
    
    for(int i=0; i<brackets.size(); i++) {
        if(brackets[i] == '(') {
            st.push('(');
        } else {
            if(!st.empty() && st.top() == '(') {
                st.pop();
                max_len += 2;
            }
        }
    }

    cout << max_len << endl;

    return 0;
}