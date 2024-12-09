#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int countA = 0, countB = 0, countC = 0;

    for(char ch : s) {
        if(ch == 'a') {
            countA++;
        } else if(ch == 'b') {
            countB++;
        } else if(ch == 'c') {
            countC++;
        }
    }

    if((countA == countB && countC == countA) || 
       (countA == countC && countB == 0) ||
       (countB == countC && countA == 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}