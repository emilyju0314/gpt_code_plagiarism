#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    string s;
    cin >> s;

    int n = s.length();
    int ans[n];
    for (int k = 1; k <= n; k++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string sub = s.substr(i, j-i+1);
                if (sub.length() == k) {
                    if (isPalindrome(sub)) {
                        count++;
                    }
                }
            }
        }
        ans[k-1] = count;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}