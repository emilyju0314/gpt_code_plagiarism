#include <iostream>
#include <string>
using namespace std;

bool isMagicNumber(string num) {
    while (num.length() > 0) {
        if (num.substr(0, 3) == "144") {
            num = num.substr(3);
        } else if (num.substr(0, 2) == "14") {
            num = num.substr(2);
        } else if (num.substr(0, 1) == "1") {
            num = num.substr(1);
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    string num;
    cin >> num;

    if (isMagicNumber(num)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}