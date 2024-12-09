#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int countPossibleWinners(int k, string s) {
    int n = pow(2, k);
    bool possible[20][2] = {0};

    for (int i = 0; i < n; ++i) {
        possible[i][s.back() - '0'] = true;
        s.pop_back();
    }

    for (int i = n - 1; i >= 0; --i) {
        if (possible[i][0] && possible[i][1]) {
            possible[i / 2][0] = true;
            possible[i / 2][1] = true;
        } else if (possible[i][0]) {
            if (i % 2 == 0) {
                possible[i / 2][0] = true;
            } else {
                possible[i / 2][1] = true;
            }
        } else if (possible[i][1]) {
            if (i % 2 == 0) {
                possible[i / 2][1] = true;
            } else {
                possible[i / 2][0] = true;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (possible[i][0] && possible[i][1]) {
            count++;
        }
    }

    return count;
}

int main() {
    int k;
    string s;
    cin >> k >> s;

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int p;
        char c;
        cin >> p >> c;

        s[p - 1] = c;
        cout << countPossibleWinners(k, s) << endl;
    }

    return 0;
}