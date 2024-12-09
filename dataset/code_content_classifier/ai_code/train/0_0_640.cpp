#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    
    string s;
    cin >> s;
    
    bool found = false;
    
    for (int i = n - 1; i >= 0; i--) {
        char c = s[i];
        while (c < 'a' + p - 1) {
            c++;
            if ((i == 0 || s[i-1] != c) && (i == n - 1 || s[i+1] != c)) {
                s[i] = c;
                for (int j = i + 1; j < n; j++) {
                    char next_char = 'a';
                    while (j > 0 && next_char == s[j-1] || next_char == s[j]) {
                        next_char++;
                    }
                    if (next_char >= 'a' + p) {
                        break;
                    }
                    s[j] = next_char;
                }
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    
    if (found) {
        cout << s << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}