#include <iostream>
#include <string>

using namespace std;

bool fullyErasable(string s) {
    int countA = 0, countB = 0, countC = 0;
    
    for(char ch : s) {
        if(ch == 'A') {
            countA++;
        } else if(ch == 'B') {
            countB++;
        } else {
            countC++;
        }
    }
    
    return (countA == 0 && countB == countC) || (countA == countC && countB == 0);
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        string s;
        cin >> s;
        
        if(fullyErasable(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}