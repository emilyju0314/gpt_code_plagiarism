#include <iostream>
#include <string>

using namespace std;

string reverseString(string s) {
    string result = "";
    for(int i = s.length()-1; i >= 0; i--) {
        result += s[i];
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        string s;
        cin >> s;

        bool possible = true;
        int len = n - 2*k;
        for(int i = 0; i < k; i++) {
            if(s[i] != s[n-1-i]) {
                possible = false;
                break;
            }
        }
        if(len <= 0 || len % 2 != 0) {
            possible = false;
        }
        
        if(possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}