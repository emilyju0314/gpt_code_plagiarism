#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    string t = "";
    int n = s.length();
    
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            t += s[i];
        }
    }
    
    for(int i = n - 1; i >= 0; i--) {
        if(i % 2 != 0) {
            t += s[i];
        }
    }
    
    cout << t << endl;
    
    return 0;
}