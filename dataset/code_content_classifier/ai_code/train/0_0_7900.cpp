#include <iostream>
#include <string>

using namespace std;

int minPlayersToTalk(int n, string s) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L' && s[(i+1)%n] == 'R') {
            count++;
        } else if (s[i] == 'R' && s[(i+1)%n] == 'L') {
            count++;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        cout << minPlayersToTalk(n, s) << endl;
    }

    return 0;
}