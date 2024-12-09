#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string wires;
    cin >> wires;

    stack<char> st;

    for(char wire : wires) {
        if(!st.empty() && st.top() == wire) {
            st.pop();
        } else {
            st.push(wire);
        }
    }

    if(st.empty()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}