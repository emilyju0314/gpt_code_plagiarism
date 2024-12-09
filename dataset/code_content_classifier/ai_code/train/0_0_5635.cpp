#include <iostream>
#include <string>

using namespace std;

bool check(int i, string s) {
    if (i > 0 && s[i - 1] == '?') {
        return true;
    }
    if (i > 1 && s[i - 1] == '*' && s[i - 2] == s[i - 3]) {
        return true;
    }
    if (i > 2 && s[i - 1] == '*' && s[i - 2] == s[i - 3] && s[i - 3] == s[i - 4]) {
        return true;
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    
    int k;
    cin >> k;
    
    string result = "";
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '?' && s[i] != '*') {
            if (result.length() < k) {
                result += s[i];
            }
        } else {
            if (check(result.length(), s)) {
                result += (result.length() > 0) ? result.back() : 'a';
            }
        }
    }
    
    if (result.length() == k) {
        cout << result << endl;
    } else {
        cout << "Impossible" << endl;
    }
    
    return 0;
}