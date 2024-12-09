#include <iostream>
#include <string>

using namespace std;

int main() {
    int q;
    cin >> q;
    
    while(q--) {
        string s, t, p;
        cin >> s >> t >> p;
        
        int j = 0;
        bool possible = true;
        
        for(int i = 0; i < t.size(); i++) {
            if(j < s.size() && s[j] == t[i]) {
                j++;
            } else {
                bool found = false;
                for(int k = 0; k < p.size(); k++) {
                    if(p[k] == t[i]) {
                        p[k] = ' '; // mark character as used
                        found = true;
                        break;
                    }
                }
                if(!found) {
                    possible = false;
                    break;
                }
            }
        }
        
        if(j < s.size()) {
            possible = false;
        }
        
        cout << (possible ? "YES" : "NO") << endl;
    }
    
    return 0;
}