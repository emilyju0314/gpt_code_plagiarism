#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> snacks(n);
    vector<int> result(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> snacks[i];
    }

    stack<int> st;
    for (int i = 0; i < n; i++) {
        st.push(snacks[i]);
        while (!st.empty() && st.top() == n) {
            result[i] = st.top();
            st.pop();
            n--;
        }
    }

    for (int i = 0; i < n; i++) {
        if(result[i] != 0) {
            cout << result[i] << endl;
        } else {
            cout << endl;
        }
    }

    return 0;
}