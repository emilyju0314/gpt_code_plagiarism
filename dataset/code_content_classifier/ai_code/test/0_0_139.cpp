#include <iostream>
#include <string>

using namespace std;

bool isSquare(string s) {
    int n = s.length();
    if (n % 2 == 1) {
        return false;
    }
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[i + n / 2]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        
        if (isSquare(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}