#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string checkRegularBracketSequence(string a) {
    unordered_map<char, char> bracketPairs = {
        {'A', '('},
        {'B', '('},
        {'C', '('}
    };
    
    int n = a.size();
    for(int i = 0; i < n; i+=2) {
        if(a[i] == a[i+1]) { // same characters need to be enclosed in the same type of brackets
            bracketPairs[a[i]] = ')';
        }
    }
    
    int openCount = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == bracketPairs[a[i]]) {
            openCount++;
        } else {
            openCount--;
        }
        if(openCount < 0) {
            return "NO";
        }
    }
    
    if(openCount == 0) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        string a;
        cin >> a;
        
        cout << checkRegularBracketSequence(a) << endl;
    }
    
    return 0;
}