#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int n;
    string brackets;
    cin >> n >> brackets;

    stack<char> st;

    for (int i = 0; i < n; i++) {
        if (brackets[i] == '[') {
            if (i < n-1 && brackets[i+1] == ']') {
                cout << "[]";
                i++;
            } else {
                st.push('[');
                cout << "+-";
            }
        } else {
            st.pop();
            if (st.empty()) {
                cout << "[]";
            } else {
                cout << "-+";
            }
        }
    }

    cout << endl;

    st = stack<char>();

    for (int i = 0; i < n; i++) {
        if (brackets[i] == '[') {
            st.push('[');
            if (st.size() % 2 == 1) {
                cout << "|+";
            } else {
                cout << "||";
            }
        } else {
            if (st.size() % 2 == 1) {
                cout << "|";
            } else {
                cout << "-";
            }
            st.pop();
            if (st.empty()) {
                cout << "]";
            }
        }
    }

    cout << endl;

    return 0;
}