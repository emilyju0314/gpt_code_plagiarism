#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    transform(s.begin(), s.end(), s.begin(), ::tolower); // convert string to lowercase
    
    bool alphabets[26] = {false};
    
    for(int i = 0; i < n; i++) {
        if(isalpha(s[i])) {
            alphabets[s[i] - 'a'] = true;
        }
    }
    
    bool isPangram = true;
    
    for(int i = 0; i < 26; i++) {
        if(!alphabets[i]) {
            isPangram = false;
            break;
        }
    }
    
    if(isPangram) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}