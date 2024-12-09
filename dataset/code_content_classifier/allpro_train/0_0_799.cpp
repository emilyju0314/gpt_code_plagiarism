#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int initialScore = (s[0] == 'W' ? 1 : 0);
        int score = initialScore;
        vector<int> consecutiveWins;

        for (int i = 1; i < n; i++) {
            if (s[i] == 'W') {
                if (s[i-1] == 'W') {
                    score += 2;
                } else {
                    score++;
                }
            } else {
                consecutiveWins.push_back(score);
            }
        }

        sort(consecutiveWins.begin(), consecutiveWins.end());

        for (int win : consecutiveWins) {
            if (k == 0 || win == 0) {
                break;
            }
            score += 2;
            k--;
        }

        if (k > 0 && initialScore == 0) {
            score++;
        }

        cout << score << endl;
    }

    return 0;
}