#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        string s;
        cin >> s;
        
        bool possible = false;
        
        for(int i = 0; i < s.length() - 1; i++) {
            if((s[i] == 'A' && s[i+1] == 'B') || (s[i] == 'B' && s[i+1] == 'C') || (s[i] == 'C' && s[i+1] == 'A')) {
                possible = true;
                break;
            }
        }
        
        if(possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}