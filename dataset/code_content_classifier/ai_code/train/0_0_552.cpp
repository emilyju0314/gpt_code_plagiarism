#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
    int n = s.length();
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    cin >> s;

    int n = s.length();
    int evenGoodSubstrings = 0;
    int oddGoodSubstrings = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string sub = s.substr(i, j - i + 1);
            if (isPalindrome(sub)) {
                if (sub.length() % 2 == 0) {
                    evenGoodSubstrings++;
                } else {
                    oddGoodSubstrings++;
                }
            }
        }
    }

    cout << evenGoodSubstrings << " " << oddGoodSubstrings << endl;

    return 0;
}