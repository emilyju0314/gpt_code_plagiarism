#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_palindrome(const string& s) {
    int n = s.length();
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n-i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    
    int n = s.length();
    string palindrome;
    
    // Find a palindrome of length 100 if it exists
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (j - i + 1 == 100) {
                string sub = s.substr(i, j-i+1);
                if (is_palindrome(sub)) {
                    palindrome = sub;
                    break;
                }
            }
        }
        if (!palindrome.empty()) {
            break;
        }
    }
    
    // If palindrome of length 100 not found, find any palindrome
    if (palindrome.empty()) {
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (is_palindrome(s.substr(i, j-i+1))) {
                    palindrome = s.substr(i, j-i+1);
                    break;
                }
            }
            if (!palindrome.empty()) {
                break;
            }
        }
    }
    
    cout << palindrome << endl;
    
    return 0;
}