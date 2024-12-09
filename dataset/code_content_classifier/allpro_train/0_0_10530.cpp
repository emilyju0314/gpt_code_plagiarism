#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int m;
    cin >> m;

    vector<pair<int, int>> operations(m); // pair to store pi and ti
    vector<int> values(m); // stores xi if ti is 1

    for (int i = 0; i < m; i++) {
        int pi, ti;
        cin >> pi >> ti;
        operations[i] = {pi, ti};
        if (ti == 1) {
            int xi;
            cin >> xi;
            values[i] = xi;
        }
    }

    stack<int> st;

    vector<int> result(m, -1); // initialize result to -1
    for (int i = m - 1; i >= 0; i--) {
        int pi = operations[i].first;
        int ti = operations[i].second;

        if (ti == 1) {
            st.push(values[i]);
        } else {
            if (!st.empty()) {
                st.pop();
            }
        }

        if (st.empty()) {
            result[pi - 1] = -1;
        } else {
            result[pi - 1] = st.top();
        }
    }

    for (int res : result) {
        cout << res << endl;
    }

    return 0;
}