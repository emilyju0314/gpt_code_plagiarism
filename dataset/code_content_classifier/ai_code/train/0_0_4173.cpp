#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    stack<char> st;
    int unmatchedLeft = 0, unmatchedRight = 0;
    
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else {
            if (!st.empty()) {
                st.pop();
            } else {
                unmatchedRight++;
            }
        }
    }
    
    unmatchedLeft = st.size();
    
    if (unmatchedLeft == 0 && unmatchedRight == 0) {
        cout << 0 << endl;
    } else if ((unmatchedLeft + unmatchedRight) % 2 == 1) {
        cout << -1 << endl;
    } else {
        cout << (unmatchedLeft + unmatchedRight) / 2 + 2 << endl;
    }
    
    return 0;
}