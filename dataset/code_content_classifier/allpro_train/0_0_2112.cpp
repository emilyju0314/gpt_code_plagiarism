#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

bool checkRule(string p, string t, int l, int r) {
    int count = 0;
    for (int i = 0; i <= p.length() - t.length(); i++) {
        string sub = p.substr(i, t.length());
        if (sub == t) {
            count++;
        }
    }
    return (count >= l && count <= r);
}

int main() {
    string s;
    cin >> s;
    
    int n;
    cin >> n;
    
    unordered_set<string> goodSubstrings;
    
    for (int i = 0; i < n; i++) {
        string p;
        int l, r;
        cin >> p >> l >> r;
        
        for (int j = 0; j <= s.length(); j++) {
            for (int k = 1; k <= s.length() - j; k++) {
                string sub = s.substr(j, k);
                if (checkRule(p, sub, l, r)) {
                    goodSubstrings.insert(sub);
                }
            }
        }
    }
    
    cout << goodSubstrings.size() << endl;
    
    return 0;
}