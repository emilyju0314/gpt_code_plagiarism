#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int n = s.length();
    
    string prefix = "", suffix = "";
    for (int i = 1; i < n; i++) {
        if (s.substr(0,i) == s.substr(n-i,i)) {
            prefix = s.substr(0,i);
        }
    }
    
    for (int i = 1; i < n; i++) {
        if (s.substr(n-i,i) == prefix) {
            suffix = s.substr(n-i,i);
        }
    }
    
    if (prefix != "" && suffix != "") {
        cout << prefix << endl;
    } else {
        cout << "Just a legend" << endl;
    }
    
    return 0;
}