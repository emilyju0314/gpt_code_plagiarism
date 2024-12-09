#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinErasedSymbols(string s) {
    vector<int> freq(26, 0);
    int n = s.length();
    
    for(char c : s) {
        freq[c - 'a']++;
    }
    
    int oddCount = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i] % 2 != 0) {
            oddCount++;
        }
    }
    
    if(oddCount > 1) {
        return -1;
    }
    
    int minErased = 0;
    for(int i = 0; i < n/2; i++) {
        if(s[i] != s[n-i-1]) {
            minErased++;
        }
    }
    
    return minErased;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        
        cout << findMinErasedSymbols(s) << endl;
    }
    
    return 0;
}