#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;

    bool isVowel = false;

    for (char c : input) {
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            isVowel = true;
            break;
        }
    }

    if (isVowel) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}