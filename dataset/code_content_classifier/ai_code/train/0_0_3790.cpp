#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 0, cntB = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'A') {
            cntB = 0;
        } else if (s[i] == 'B') {
            cntB++;
        } else {
            ans += cntB;
        }
    }

    cout << ans << endl;

    return 0;
}