#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string S;
    cin >> S;

    if (S == "zyxwvutsrqponmlkjihgfedcba") {
        cout << "-1" << endl;
    } else {
        int n = S.size();
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        string next_word = "-1";

        if (n < 26) {
            for (int i = 0; i < 26; i++) {
                if (find(S.begin(), S.end(), alphabet[i]) == S.end()) {
                    next_word = S + alphabet[i];
                    break;
                }
            }
        }

        cout << next_word << endl;
    }

    return 0;
}