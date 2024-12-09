#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPossible(string S) {
    reverse(S.begin(), S.end());
    string dream = "maerd";
    string dreamer = "remaerd";
    string erase = "esare";
    string eraser = "resare";
    
    int pos = 0;
    while(pos < S.length()) {
        if(S.substr(pos, 5) == dream) {
            pos += 5;
        } else if(S.substr(pos, 7) == dreamer) {
            pos += 7;
        } else if(S.substr(pos, 5) == erase) {
            pos += 5;
        } else if(S.substr(pos, 6) == eraser) {
            pos += 6;
        } else {
            return false;
        }
    }
    
    return true;
}

int main() {
    string S;
    cin >> S;
    
    if(isPossible(S)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}