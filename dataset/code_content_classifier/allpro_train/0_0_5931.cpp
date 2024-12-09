#include <iostream>
#include <stack>
#include <map>

using namespace std;

int main() {
    string s;
    cin >> s;

    map<char, char> opening = {{'<', '>'}, {'{', '}'}, {'[', ']'}, {'(', ')'}};
    map<char, char> closing = {{'>', '<'}, {'}', '{'}, {']', '['}, {')', '('}};

    stack<char> st;

    int replaceCount = 0;

    for (char c : s) {
        if (opening.count(c) > 0) {
            st.push(c);
        } else if (closing.count(c) > 0) {
            if (st.empty() || opening[st.top()] != c) {
                replaceCount++;
            } else {
                st.pop();
            }
        }
    }

    if (!st.empty()) {
        cout << "Impossible" << endl;
    } else {
        cout << replaceCount << endl;
    }

    return 0;
}