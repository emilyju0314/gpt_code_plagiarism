#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int queryType;
        cin >> queryType;
        
        if (queryType == 1) {
            int x;
            char c;
            cin >> x >> c;
            s[x - 1] = c; // Updating the DNA strand
            
        } else if (queryType == 2) {
            int l, r;
            string e;
            cin >> l >> r >> e;
            
            int impact = 0;
            string sub = s.substr(l - 1, r - l + 1);
            string repeatedE = e;
            
            while (repeatedE.size() < sub.size()) {
                repeatedE += e;
            }
            
            for (int j = 0; j < sub.size(); j++) {
                if (sub[j] == repeatedE[j]) {
                    impact++;
                }
            }
            
            cout << impact << endl;
        }
    }
    
    return 0;
}