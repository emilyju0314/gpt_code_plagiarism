#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string keyboard, word;
        cin >> keyboard >> word;

        int pos[26];
        for (int i = 0; i < 26; i++) {
            pos[keyboard[i] - 'a'] = i;
        }

        int time = 0;
        int currPos = 0;
        for (char c : word) {
            time += abs(pos[c - 'a'] - currPos);
            currPos = pos[c - 'a'];
        }

        cout << time << endl;
    }

    return 0;
}