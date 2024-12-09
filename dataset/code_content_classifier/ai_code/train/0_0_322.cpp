#include <iostream>
#include <string>

using namespace std;

bool isMirrorString(string S) {
    string mirror = S;
    for(char& c : mirror) {
        if(c == 'b') c = 'd';
        else if(c == 'd') c = 'b';
        else if(c == 'p') c = 'q';
        else if(c == 'q') c = 'p';
    }

    reverse(mirror.begin(), mirror.end());

    if(S == mirror) return true;
    return false;
}

int main() {
    string S;
    cin >> S;

    if(isMirrorString(S)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}