#include <iostream>
#include <vector>

using namespace std;

bool canWin(int a, int b, string s) {
    vector<int> emptyPrefix(s.size()+1);
    int emptyCnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            emptyCnt++;
        }
        emptyPrefix[i+1] = emptyCnt;
    }
    
    if (emptyPrefix[a] > emptyPrefix[b]) {
        return true;
    }
    
    for (int i = 1; i+a <= s.size(); i++) {
        int emptyNeeded = emptyPrefix[i+a] - emptyPrefix[i-1];
        if (emptyNeeded > emptyPrefix[i+b-1] - emptyPrefix[i-1]) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int q;
    cin >> q;
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        
        string s;
        cin >> s;
        
        if (canWin(a, b, s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}