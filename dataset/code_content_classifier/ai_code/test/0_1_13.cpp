#include <iostream>
#include <string>

using namespace std;

bool canFullyEraseString(string s) {
    int countA = 0, countB = 0, countC = 0;
    for(char c : s) {
        if(c == 'A') {
            countA++;
        } else if(c == 'B') {
            countB++;
        } else {
            countC++;
        }
    }
    
    return (countA == 0 && countB == countC) || (countB == 0 && countA == countC) || (countC == 0 && countA == countB);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        if(canFullyEraseString(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}