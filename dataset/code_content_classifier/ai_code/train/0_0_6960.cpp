#include <iostream>
#include <string>

using namespace std;

bool isValidEmail(const string& substr) {
    int n = substr.length();
    bool hasAlphaNumeric = false;
    bool hasDot = false;
    bool hasAt = false;
    
    if (!isalpha(substr[0])) {
        return false;
    }
    
    for (int i = 0; i < n; i++) {
        if (isalnum(substr[i])) {
            hasAlphaNumeric = true;
        } else if (substr[i] == '@') {
            if (hasAt || !hasAlphaNumeric) {
                return false;
            }
            hasAt = true;
            hasAlphaNumeric = false;
        } else if (substr[i] == '.') {
            if (!hasAlphaNumeric || hasDot) {
                return false;
            }
            hasDot = true;
            hasAlphaNumeric = false;
        } else if (substr[i] == '_') {
            // underscore is allowed, do nothing
        } else {
            return false;
        }
    }
    
    return hasAlphaNumeric && hasDot;
}

int main() {
    string s;
    cin >> s;
    
    long long ans = 0;
    int n = s.length();
    
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            string substr = s.substr(l, r - l + 1);
            if (isValidEmail(substr)) {
                ans++;
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}