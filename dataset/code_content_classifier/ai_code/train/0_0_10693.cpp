#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    stack<int> st;
    vector<int> left(n), right(n);

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        
        if (st.empty()) {
            left[i] = 0;
        } else {
            left[i] = st.top() + 1;
        }

        st.push(i);
    }

    while (!st.empty()) {
        st.pop();
    }

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        
        if (st.empty()) {
            right[i] = n - 1;
        } else {
            right[i] = st.top() - 1;
        }

        st.push(i);
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int len = right[i] - left[i] + 1;
        ans[len - 1] = max(ans[len - 1], heights[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}