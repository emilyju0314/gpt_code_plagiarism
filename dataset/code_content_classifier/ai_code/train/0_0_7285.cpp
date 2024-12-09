#include <iostream>
#include <string>
using namespace std;

int countAwesomeSubstrings(string s) {
    int n = s.length();
    int cnt1 = 0;
    for (char& c : s) {
        if (c == '1') {
            cnt1++;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == '1') {
                cnt++;
            }
            if (cnt > 0 && n % cnt == 0) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    
    int ans = countAwesomeSubstrings(s);
    cout << ans << endl;
    
    return 0;
}