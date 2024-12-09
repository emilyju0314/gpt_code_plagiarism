#include <iostream>
#include <string>

using namespace std;

bool isQuasiPalindromic(int x) {
    string s = to_string(x);
    string reverse_s = s;
    reverse(reverse_s.begin(), reverse_s.end());
    
    while (s.length() > 0 && s[0] == '0') {
        s.erase(0, 1);
    }
    
    if (s == reverse_s) {
        return true;
    }
    
    return false;
}

int main() {
    int x;
    cin >> x;
    
    if (isQuasiPalindromic(x)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}