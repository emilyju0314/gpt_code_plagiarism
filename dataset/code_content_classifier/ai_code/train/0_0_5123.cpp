#include <iostream>
#include <vector>
#include <algorithm>

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
    int n, m;
    cin >> n >> m;

    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    string palindrome;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string temp = strings[i] + strings[j];
            string reverse_temp = temp;
            reverse(reverse_temp.begin(), reverse_temp.end());

            if (temp == reverse_temp && temp.length() > palindrome.length()) {
                palindrome = temp;
            }
        }
    }

    cout << palindrome.length() << endl;
    cout << palindrome << endl;

    return 0;
}