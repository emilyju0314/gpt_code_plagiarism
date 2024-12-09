#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    cin >> s;

    bool found = false;

    for (char c = 'a'; c <= 'z'; c++) {
        string temp = s + c;
        if (isPalindrome(temp)) {
            cout << temp << endl;
            found = true;
            break;
        }
        temp = c + s;
        if (isPalindrome(temp)) {
            cout << temp << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "NA" << endl;
    }

    return 0;
}