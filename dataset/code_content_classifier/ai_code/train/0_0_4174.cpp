#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isCorrectBracketSequence(string s, vector<int>& types) {
    stack<int> st;
    
    for (char c : s) {
        int t = types[c - '0' - 1];
        if (t > 0) {
            st.push(t);
        } else {
            if (st.empty() || st.top() != -t) {
                return false;
            }
            st.pop();
        }
    }
    
    return st.empty();
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> types(k);
    for (int i = 0; i < k; i++) {
        cin >> types[i];
    }
    
    string s;
    cin >> s;
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int pos, t;
            cin >> pos >> t;
            s[pos - 1] = t > 0 ? (t + '0') : (-t + '0');
        } else {
            int l, r;
            cin >> l >> r;
            string sub = s.substr(l - 1, r - l + 1);
            if (isCorrectBracketSequence(sub, types)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    
    return 0;
}