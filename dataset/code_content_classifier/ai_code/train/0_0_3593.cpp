#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    vector<int> left(n), right(n); // store the index of the nearest smaller element on the left and right
    stack<int> st;

    for(int i = 0; i < n; i++) {
        while(!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while(!st.empty()) {
        st.pop();
    }

    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    vector<int> answer(n, 0);
    for(int i = 0; i < n; i++) {
        int size = right[i] - left[i] - 1;
        answer[size-1] = max(answer[size-1], heights[i]);
    }

    for(int i = n-2; i >= 0; i--) {
        answer[i] = max(answer[i], answer[i+1]);
    }

    for(int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}