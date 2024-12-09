#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    stack<int> st;
    vector<pair<int, int>> operations;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            if (!st.empty()) {
                operations.push_back(make_pair(st.top(), i));
                st.pop();
            }
        }
    }
    
    cout << operations.size() << endl;
    for (auto op : operations) {
        cout << "2" << endl;
        cout << op.first + 1 << " " << op.second + 1 << endl;
    }
    
    return 0;
}