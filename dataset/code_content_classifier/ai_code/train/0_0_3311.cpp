#include <iostream>
#include <stack>
#include <string>

using namespace std;

int maxMoves(string s) {
    stack<char> st;
    int count = 0;

    for(char c : s) {
        if(st.empty()) {
            st.push(c);
        } else {
            if((st.top() == '[' && c == ']') || (st.top() == '(' && c == ')')) {
                st.pop();
                count++;
            } else {
                st.push(c);
            }
        }
    }

    return count / 2;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        cout << maxMoves(s) << endl;
    }

    return 0;
}