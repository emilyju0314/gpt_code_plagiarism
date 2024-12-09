#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int takahashi = 0;
    int aoki = 0;

    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] != s[i-1] && s[i] != s[i+1]) {
            takahashi++;
        } else {
            aoki++;
        }
    }

    if (takahashi > aoki) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    return 0;
}