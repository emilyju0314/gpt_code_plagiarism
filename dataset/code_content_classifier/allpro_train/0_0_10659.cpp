#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canCoexist(string word, string religion1, string religion2, string religion3) {
    int n = word.length();
    int m1 = religion1.length();
    int m2 = religion2.length();
    int m3 = religion3.length();

    vector<vector<vector<bool>>> dp(m1 + 1, vector<vector<bool>>(m2 + 1, vector<bool>(m3 + 1, false)));
    
    dp[0][0][0] = true;

    for (int i = 0; i <= m1; i++) {
        for (int j = 0; j <= m2; j++) {
            for (int k = 0; k <= m3; k++) {
                if (i < m1 && word[n - 1] == religion1[i]) {
                    dp[i + 1][j][k] |= dp[i][j][k];
                }
                if (j < m2 && word[n - 1] == religion2[j]) {
                    dp[i][j + 1][k] |= dp[i][j][k];
                }
                if (k < m3 && word[n - 1] == religion3[k]) {
                    dp[i][j][k + 1] |= dp[i][j][k];
                }
                dp[i][j][k] |= dp[i][j][k];
            }
        }
    }

    return dp[m1][m2][m3];
}

int main() {
    int n, q;
    cin >> n >> q;
    
    string word;
    cin >> word;

    string religion1 = "";
    string religion2 = "";
    string religion3 = "";

    for (int i = 0; i < q; i++) {
        char op;
        cin >> op;
        if (op == '+') {
            int religion;
            char c;
            cin >> religion >> c;
            if (religion == 1) {
                religion1 += c;
            } else if (religion == 2) {
                religion2 += c;
            } else {
                religion3 += c;
            }
        } else {
            int religion;
            cin >> religion;
            if (religion == 1) {
                religion1.pop_back();
            } else if (religion == 2) {
                religion2.pop_back();
            } else {
                religion3.pop_back();
            }
        }

        if (canCoexist(word, religion1, religion2, religion3)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}