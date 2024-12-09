#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int decodedNumber = 0;
    int currentDigit = 0;
    
    for(int i=0; i<n; i++) {
        if(s[i] == '1') {
            currentDigit++;
        } else {
            decodedNumber = decodedNumber * 10 + currentDigit;
            currentDigit = 0;
        }
    }
    
    decodedNumber = decodedNumber * 10 + currentDigit;
    
    cout << decodedNumber;
    
    return 0;
}