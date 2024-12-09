#include <iostream>
#include <string>

using namespace std;

bool canFullyEraseString(string s) {
    int numA = 0, numB = 0, numC = 0;
    for (char c : s) {
        if (c == 'A') {
            numA++;
        } else if (c == 'B') {
            numB++;
        } else {
            numC++;
        }
    }
    return (numA == 0 && numB == 0) || (numB == 0 && numC == 0);
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;

        if (canFullyEraseString(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}