#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    
    int zeros = 0, ones = 0;
    for(int i = 0; i < 2*n; i++) {
        if(s[i] == '0' && t[i] == '1') ones++;
        if(s[i] == '1' && t[i] == '0') zeros++;
    }
    
    if(zeros == ones) cout << "Draw" << endl;
    else if(zeros > ones) cout << "First" << endl;
    else cout << "Second" << endl;
    
    return 0;
}