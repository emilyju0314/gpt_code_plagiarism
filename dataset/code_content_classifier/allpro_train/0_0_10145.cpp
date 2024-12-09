#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxLengthSubstring(string s, string t) {
    int n = s.size(), m = t.size();
    vector<int> pref(n, -1), suff(n, -1);
    
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[j]) {
            pref[i] = j;
            j++;
            if (j == m) {
                break;
            }
        }
    }
    
    j = m-1;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == t[j]) {
            suff[i] = j;
            j--;
            if (j < 0) {
                break;
            }
        }
    }
    
    int maxLen = 0;
    
    for (int i = 1; i < n; i++) {
        if (pref[i] != -1 && suff[i-1] != -1) {
            maxLen = max(maxLen, suff[i-1] - pref[i]);
        }
    }
    
    return maxLen;
}

int main() {
    string s, t;
    cin >> s >> t;
    
    int result = maxLengthSubstring(s, t);
    cout << result << endl;
    
    return 0;
}