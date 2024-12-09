#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int zeros = count(s.begin(), s.end(), '0');
        if(zeros == 1 || isPalindrome(s)) {
            if(zeros % 2 == 0) {
                cout << "BOB" << endl;
            } else {
                cout << "ALICE" << endl;
            }
        } else {
            if(zeros <= 2) {
                cout << "DRAW" << endl;
            } else {
                cout << "ALICE" << endl;
            }
        }
    }

    return 0;
}