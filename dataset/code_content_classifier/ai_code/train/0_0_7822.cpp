#include <iostream>
#include <stack>

using namespace std;

int main() {
    string s;
    cin >> s;

    stack<int> st;
    int maxLen = 0;
    int startIdx = -1;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[') {
            st.push(i);
        } else if (s[i] == ']') {
            if (!st.empty()) {
                int start = st.top();
                st.pop();
                int len = i - start + 1;
                if (len > maxLen) {
                    maxLen = len;
                    startIdx = start;
                }
            }
        }
    }

    cout << maxLen << endl;
    if (startIdx != -1) {
        cout << s.substr(startIdx, maxLen) << endl;
    }

    return 0;
}