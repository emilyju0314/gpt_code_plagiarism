#include <iostream>
#include <string>

using namespace std;

bool isValidHQProgram(string s) {
    int hCount = 0;
    for (char c : s) {
        if (c == 'H') {
            hCount++;
        } else if (c == 'Q') {
            break;
        }
    }
    int qCount = 0;
    for (char c : s) {
        if (c == 'Q') {
            qCount++;
        } else if (c == 'H') {
            break;
        }
    }
    if (hCount == 0 || qCount == 0) {
        return false;
    }
    
    int qIndex = s.find('Q');
    int hAfterQCount = count(s.begin() + qIndex, s.end(), 'H');
    
    return hCount == hAfterQCount;
}

int main() {
    string s;
    cin >> s;
    
    if (isValidHQProgram(s)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}