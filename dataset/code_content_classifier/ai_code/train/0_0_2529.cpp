#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isIrreducibleAnagram(string s) {
    int n = s.length();
    unordered_map<char, int> freq;
    
    for (char c : s) {
        freq[c]++;
    }
    
    int oddCount = 0;
    for (auto it = freq.begin(); it != freq.end(); it++) {
        if (it->second % 2 != 0) {
            oddCount++;
        }
    }
    
    return oddCount <= 1;
}

int main() {
    string s;
    cin >> s;
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        
        string sub = s.substr(l-1, r-l+1);
        if (isIrreducibleAnagram(sub)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}