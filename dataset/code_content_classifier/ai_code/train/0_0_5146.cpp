#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    
    string s;
    cin >> s;
    
    bool found = false;
    
    for (int i = n-1; i >= 0; i--) {
        if (s[i] - 'a' < p - 1) {
            s[i]++;
            
            for (int j = i+1; j < n; j++) {
                s[j] = 'a'; // change all characters after i to 'a'
            }
            
            found = true;
            break;
        }
    }
    
    if (found) {
        bool valid = true;
        for (int i = 0; i < n-1; i++) {
            if (s[i] == s[i+1] || (i > 0 && s[i] == s[i-1])) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            cout << s << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}