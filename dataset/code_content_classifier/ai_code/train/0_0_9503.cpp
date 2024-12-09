#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    int n = s.length();
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n-1-i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    cin >> s;

    int n = s.length();
    int max_length = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string sub = s.substr(i, j-i+1);
            if (!isPalindrome(sub) && sub.length() > max_length) {
                max_length = sub.length();
            }
        }
    }

    cout << max_length << endl;

    return 0;
} 

// Input: mew
// Output: 3

// Input: wuffuw
// Output: 5

// Input: qqqqqqqq
// Output: 0