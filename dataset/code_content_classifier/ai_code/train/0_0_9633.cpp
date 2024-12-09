#include <iostream>
#include <string>

using namespace std;

string findLongestPalindrome(string s) {
    int n = s.length();
    string res = "";

    for (int i = 0; i < n; i++) {
        if (s[i] == s[n - 1]) {
            bool isPalindrome = true;
            for (int j = i + 1, k = n - 2; j < k; j++, k--) {
                if (s[j] != s[k]) {
                    isPalindrome = false;
                    break;
                }
            }
            if (isPalindrome) {
                string prefix = s.substr(0, i + 1);
                string suffix = s.substr(i + 1, n - i - 1);
                string palindrome = prefix;
                reverse(suffix.begin(), suffix.end());
                palindrome += suffix;
                if (palindrome.length() > res.length()) {
                    res = palindrome;
                }
            }
        }
    }
    
    return res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        cout << findLongestPalindrome(s) << endl;
    }

    return 0;
}