#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<vector<int>> charCount(s.length(), vector<int>(26, 0));

    // Precompute frequency of each character for all substrings
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < 26; j++) {
            int prevCount = (i == 0) ? 0 : charCount[i - 1][j];
            charCount[i][j] = prevCount + (s[i] == 'a' + j);
        }
    }

    int m;
    cin >> m;

    while (m--) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        bool aliceWins = false;

        if (l == 0) {
            // If Alice chooses the character appearing odd number of times, she will win
            for (int i = 0; i < 26; i++) {
                int freq = charCount[r][i];
                if (freq % 2 == 1) {
                    aliceWins = true;
                    break;
                }
            }
        } else {
            // If Alice can make the substring even length, she will win
            for (int i = 0; i < 26; i++) {
                int freq = charCount[r][i] - charCount[l - 1][i];
                if (freq % 2 == 1) {
                    aliceWins = true;
                    break;
                }
            }
        }

        if (aliceWins) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }

    return 0;
}