#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int uppercaseCount = 0;
    int lowercaseCount = 0;
    
    for(int i = 0; i < s.length(); i++) {
        if(isupper(s[i])) {
            uppercaseCount++;
        } else {
            lowercaseCount++;
        }
    }
    
    if(uppercaseCount > lowercaseCount) {
        for(int i = 0; i < s.length(); i++) {
            s[i] = toupper(s[i]);
        }
    } else {
        for(int i = 0; i < s.length(); i++) {
            s[i] = tolower(s[i]);
        }
    }
    
    cout << s << endl;
    
    return 0;
}