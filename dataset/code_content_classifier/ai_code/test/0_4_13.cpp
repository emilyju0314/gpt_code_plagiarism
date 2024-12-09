#include <iostream>
#include <string>
using namespace std;

bool canFullyErase(string s) {
    int countA = 0, countB = 0, countC = 0;
    for (char c : s) {
        if (c == 'A') {
            countA++;
        } else if (c == 'B') {
            countB++;
        } else {
            countC++;
        }
    }
    
    return (countA == 0 && countB == countC) || (countB == 0 && countA == countC);
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        
        if (canFullyErase(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}