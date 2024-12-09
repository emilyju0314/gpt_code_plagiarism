#include <iostream>
#include <string>

using namespace std;

int main() {
    int k;
    string n;
    cin >> k >> n;

    int sumOfDigits = 0;
    for(char c : n) {
        sumOfDigits += c - '0';
    }

    int diff = 0;
    int required = k - sumOfDigits;
    
    for(int i = 0; i < n.length(); i++) {
        int digit = n[i] - '0';
        if(required <= 0) break;
        if(9 - digit >= required) {
            diff++;
            required = 0;
        } else {
            diff += 9 - digit;
            required -= 9 - digit;
        }
    }

    cout << diff << endl;

    return 0;
}