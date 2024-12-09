#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        string s;
        cin >> s;
        
        string w = "";
        for(int j = 0; j < n; j++) {
            if(s[j] == '0' || s[n+j-1] == '0') {
                w += '0';
            } else {
                w += '1';
            }
        }
        
        cout << w << endl;
    }
    
    return 0;
}