#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countGoodSubstrings(string s) {
    int n = s.length();
    vector<int> pref(n), suf(n);
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            pref[i] = 1;
        } else {
            pref[i] = (s[i] == s[i - 1]) ? pref[i - 1] + 1 : 1;
        }
    }
    
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            suf[i] = 1;
        } else {
            suf[i] = (s[i] == s[i + 1]) ? suf[i + 1] + 1 : 1;
        }
    }
    
    int ans = n;
    for (int i = 1; i < n - 1; i++) {
        if (s[i - 1] == s[i + 1]) {
            ans += min(pref[i - 1], suf[i + 1]);
        }
    }
    
    return ans;
}

int main() {
    int n;
    string s;
    
    cin >> n;
    cin >> s;
    
    int result = countGoodSubstrings(s);
    cout << result << endl;
    
    return 0;
}