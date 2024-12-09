#include <iostream>
#include <string>

using namespace std;

int calculate_check_digit(string s) {
    int q[11] = {2, 3, 4, 5, 6, 7, 2, 3, 4, 5, 6};
    int unknown_digit = -1;
    int sum = 0;
    
    for (int i = 0; i < 11; i++) {
        if (s[i] == '?') {
            unknown_digit = i;
        } else {
            sum += (s[i] - '0') * q[i];
        }
    }
    
    if (s[11] == '?') {
        for (int i = 0; i <= 9; i++) {
            if ((sum + i * q[unknown_digit]) % 11 == 1) {
                return i;
            }
        }
        return -1; // No valid digit found
    } else {
        int check_digit = (11 - (sum % 11)) % 11;
        if (s[11] == '0' && check_digit == 0) {
            return -1;
        } else if (s[11] == '1' && check_digit == 1) {
            return -1;
        } else {
            return -1; // Conflict with given check digit
        }
    }
}

int main() {
    string s;
    cin >> s;
    
    int unknown_digit = calculate_check_digit(s);
    
    if (unknown_digit == -1) {
        cout << "MULTIPLE" << endl;
    } else {
        cout << unknown_digit << endl;
    }
    
    return 0;
}