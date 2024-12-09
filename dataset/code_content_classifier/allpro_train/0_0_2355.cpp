#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isPossible(string s, string t) {
    unordered_map<char, int> freqS, freqT;
    
    for(char c : s) {
        freqS[c]++;
    }
    
    for(char c : t) {
        freqT[c]++;
    }
    
    return freqS == freqT;
}

int main() {
    int q;
    cin >> q;
    
    while(q--) {
        int n;
        cin >> n;
        
        string s, t;
        cin >> s >> t;
        
        if(isPossible(s, t)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}