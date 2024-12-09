#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        stack<char> st;
        vector<int> freq(26);

        for(int i = s.size()-1; i >= 0; i--) {
            freq[s[i]-'a']++;
        }

        for(int i = s.size()-1; i >= 0; i--) {
            char c = s[i];

            if(freq[c-'a'] > 1) {
                while(!st.empty() && st.top() < c && freq[st.top()-'a'] > 1) {
                    freq[st.top()-'a']--;
                    st.pop();
                }
                st.push(c);
                freq[c-'a']--;
            } else {
                freq[c-'a']--;
            }
        }

        string result = "";
        while(!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        cout << result << endl;
    }

    return 0;
}