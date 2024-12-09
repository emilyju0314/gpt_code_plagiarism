#include <iostream>
#include <string>

using namespace std;

bool isMirrorWord(string word) {
    string mirror = "AHIMOTUVWXY";
    string reversed = word;
    reverse(reversed.begin(), reversed.end());
    
    for(int i = 0; i < word.length(); i++) {
        if(mirror.find(word[i]) == string::npos || word[i] != reversed[i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    string word;
    cin >> word;
    
    if(isMirrorWord(word)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}