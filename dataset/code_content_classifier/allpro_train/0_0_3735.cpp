#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    return c == 'A' || c == 'O' || c == 'Y' || c == 'E' || c == 'U' || c == 'I' || c == 'a' || c == 'o' || c == 'y' || c == 'e' || c == 'u' || c == 'i';
}

int main() {
    string s;
    cin >> s;
    
    string result = "";
    for(int i = 0; i < s.length(); i++) {
        if(!isVowel(s[i])) {
            result += ".";
            if(isupper(s[i])) {
                result += tolower(s[i]);
            } else {
                result += s[i];
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}