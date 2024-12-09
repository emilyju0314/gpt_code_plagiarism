#include <iostream>
#include <algorithm>
using namespace std;

bool is_palindrome(string s) {
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        
        sort(s.begin(), s.end());
        
        int n = s.length();
        if (s[0] == '0') {
            for (int i = 1; i < n; i++) {
                if (s[i] != '0') {
                    swap(s[0], s[i]);
                    break;
                }
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] % 2 == 0) {
                swap(s[i], s[n - 1]);
                break;
            }
        }
        
        if (is_palindrome(s)) {
            cout << s << endl;
        } else {
            prev_permutation(s.begin(), s.end());
            cout << s << endl;
        }
    }
    
    return 0;
}