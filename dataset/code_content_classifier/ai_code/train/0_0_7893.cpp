#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;

        string s;
        cin >> s;

        int wins = (n + 1) / 2;

        int rock = 0, paper = 0, scissors = 0;
        for (char hand : s) {
            if (hand == 'R') {
                rock++;
            } else if (hand == 'P') {
                paper++;
            } else {
                scissors++;
            }
        }

        int wins_rock = min(rock, c);
        int wins_paper = min(paper, a);
        int wins_scissors = min(scissors, b);

        if (wins_rock + wins_paper + wins_scissors < wins) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            string result = "";

            for (char hand : s) {
                if (hand == 'R' && c > 0) {
                    result += "P";
                    c--;
                } else if (hand == 'P' && a > 0) {
                    result += "S";
                    a--;
                } else if (hand == 'S' && b > 0) {
                    result += "R";
                    b--;
                } else {
                    result += ".";
                }
            }

            for (char& hand : result) {
                if (hand == '.') {
                    if (a > 0) {
                        hand = 'P';
                        a--;
                    } else if (b > 0) {
                        hand = 'R';
                        b--;
                    } else {
                        hand = 'S';
                        c--;
                    }
                }
            }

            cout << result << endl;
        }
    }

    return 0;
}