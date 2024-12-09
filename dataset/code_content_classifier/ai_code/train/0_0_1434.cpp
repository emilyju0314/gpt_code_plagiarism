#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    stack<int> st;
    vector<int> dp(s.size(), 0);
    int maxLength = 0, count = 1;
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            st.push(i);
        } else {
            if(!st.empty()) {
                int start = st.top();
                st.pop();
                if(start > 0 && s[start-1] == ')' && dp[start-1] > 0) {
                    dp[i] = dp[start-1] + i - start + 1;
                    if((i - start + 1) == dp[start-1]) {
                        count++;
                    } else {
                        count = 1;
                    }
                    maxLength = max(maxLength, dp[i]);
                }
            }
        }
    }
    
    if(maxLength == 0) {
        cout << "0 1" << endl;
    } else {
        cout << maxLength << " " << count << endl;
    }
    
    return 0;
}