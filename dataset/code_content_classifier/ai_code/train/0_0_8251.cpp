#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        
        bool sorted = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                sorted = true;
                break;
            }
        }
        
        if (sorted) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}