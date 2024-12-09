#include <iostream>
#include <string>

using namespace std;

char nextChar(char c) {
    return (c - 'a' + 1) % 26 + 'a';
}

int main() {
    string s;
    int K;

    cin >> s >> K;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 'a') {
            int moves = (nextChar(s[i]) - s[i] + 26) % 26;
            if (K >= moves) {
                s[i] = 'a';
                K -= moves;
            }
        }
    }

    if (K > 0) {
        s[s.length() - 1] = nextChar(s[s.length() - 1]);
        K--;
    }

    K %= 26;

    for (int i = s.length() - 1; i >= 0 && K > 0; i--) {
        if (s[i] == 'a') {
            s[i] = 'z';
            K--;
        }
    }

    cout << s << endl;

    return 0;
}