#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(const string& str) {
    int len = str.length();
    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - i - 1])
            return false;
    }
    return true;
}

bool isMirrored(const string& str) {
    string mirror = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
    int len = str.length();
    for (int i = 0; i < (len + 1) / 2; ++i) {
        if (str[i] != mirror[str[len - i - 1] - 'A'])
            return false;
    }
    return true;
}

int main() {
    string input;
    while (cin >> input) {
        bool palindrome = isPalindrome(input);
        bool mirrored = isMirrored(input);

        cout << input << " -- ";

        if (palindrome && mirrored)
            cout << "is a mirrored palindrome.";
        else if (palindrome)
            cout << "is a regular palindrome.";
        else if (mirrored)
            cout << "is a mirrored string.";
        else
            cout << "is not a palindrome.";

        cout << endl << endl;
    }
    return 0;
}
