#include <iostream>
#include <string>

using namespace std;

int main() {
    string password;
    cin >> password;

    bool hasLength = password.length() >= 6;
    bool hasNumber = false, hasUpper = false, hasLower = false;

    for(char c : password) {
        if(isdigit(c)) {
            hasNumber = true;
        } else if(isupper(c)) {
            hasUpper = true;
        } else if(islower(c)) {
            hasLower = true;
        }
    }

    if(hasLength && hasNumber && hasUpper && hasLower) {
        cout << "VALID" << endl;
    } else {
        cout << "INVALID" << endl;
    }

    return 0;
}