#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int countA = 0, countB = 0, countC = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A') {
                countA++;
            } else if (s[i] == 'B') {
                countB++;
            } else {
                countC++;
            }
        }

        if ((countA == 0 && countB == 0) || (countB == 0 && countC == 0) || (countA == 0 && countC == 0)) {
            cout << "YES" << endl;
        } else if (countA % 2 == 0 && countB % 2 == 0 && countC % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}