#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        cin >> perm[i];
    }

    stack<int> st;
    string output;

    for (int i = 0; i < n; i++) {
        int curr = perm[i];

        if (st.empty() || st.top() > curr) {
            st.push(curr);
        } else if (st.top() == curr) {
            output += "()";
            st.pop();
        } else {
            cout << ":(\n";
            return 0;
        }
    }

    if (!st.empty()) {
        cout << ":(\n";
        return 0;
    }

    cout << output << endl;

    return 0;
}