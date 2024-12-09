#include <iostream>
#include <string>

using namespace std;

int convertToDecimal(string s, int base) {
    int result = 0;
    for (char c : s) {
        int val = (isdigit(c)) ? (c - '0') : (c - 'A' + 10);
        result = result * base + val;
    }
    return result;
}

bool isValidTime(string a, string b, int base) {
    int hours = convertToDecimal(a, base);
    int minutes = convertToDecimal(b, base);
    return hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59;
}

int main() {
    string time;
    cin >> time;
    
    string delimiter = ":";
    string a = time.substr(0, time.find(delimiter));
    string b = time.substr(time.find(delimiter) + 1);
    
    bool foundValid = false;
    
    for (int base = 2; base <= 36; base++) {
        if (isValidTime(a, b, base)) {
            cout << base << " ";
            foundValid = true;
        }
    }
    
    if (!foundValid) {
        cout << "0";
    }
    
    return 0;
}