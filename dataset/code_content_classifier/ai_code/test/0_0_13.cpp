#include <iostream>
#include <string>

using namespace std;

string canEraseString(string s) {
    int countA = 0, countB = 0, countC = 0;
    
    for(char c : s) {
        if(c == 'A') countA++;
        else if(c == 'B') countB++;
        else if(c == 'C') countC++;
    }
    
    if((countA == 0 && countB == 0) || (countB == 0 && countC == 0) || (countA == 0 && countC == 0)) {
        return "YES";
    } else if((countA % 2 == 0 && countB % 2 == 0) || (countB % 2 == 0 && countC % 2 == 0) || (countA % 2 == 0 && countC % 2 == 0)) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        string s;
        cin >> s;
        cout << canEraseString(s) << endl;
    }
    
    return 0;
}