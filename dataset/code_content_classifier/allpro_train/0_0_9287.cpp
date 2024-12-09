#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isKBalanced(string s, int k) {
    vector<int> count(2);
    for (char c : s) {
        if (c == '0' || c == '1') {
            count[c - '0']++;
        }
    }
    
    int diff = count[0] - count[1];
    bool valid = true;
    for (int i = 0; i < s.size() - k + 1; i++) {
        if (s[i] == '0' || s[i] == '1') {
            diff -= (s[i] == '0' ? -1 : 1);
        }
        if (i >= k) {
            if (s[i - k] == '0' || s[i - k] == '1') {
                diff += (s[i - k] == '0' ? -1 : 1);
            }
        }
        if (diff != 0) {
            valid = false;
            break;
        }
    }
    
    return valid;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        
        if (isKBalanced(s, k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}