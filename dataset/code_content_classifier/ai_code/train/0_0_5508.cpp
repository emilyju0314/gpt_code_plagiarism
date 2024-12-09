#include <iostream>
#include <string>

using namespace std;

bool isValidSequence(string s, int n, int k) {
    int wins = 0, losses = 0;
    for (char c : s) {
        if (c == 'W') {
            wins++;
        } else if (c == 'L') {
            losses++;
        }
    }
    return (wins + k >= losses && losses + k >= wins && (wins + losses) % 2 == 0 && wins <= n / 2 && losses <= n / 2);
}

int main() {
    int n, k;
    string s;

    cin >> n >> k;
    cin >> s;

    if (!isValidSequence(s, n, k)) {
        cout << "NO";
    } else {
        int remainingWins = k, remainingLosses = k;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'W') {
                remainingWins--;
            } else if (s[i] == 'L') {
                remainingLosses--;
            } else if (s[i] == '?') {
                if (remainingWins > remainingLosses) {
                    s[i] = 'L';
                    remainingLosses--;
                } else {
                    s[i] = 'W';
                    remainingWins--;
                }
            }
        }
        cout << s;
    }

    return 0;
}