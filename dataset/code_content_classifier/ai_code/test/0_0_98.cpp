#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string keyboard, word;
        cin >> keyboard >> word;

        vector<int> positions(26);

        for (int i = 0; i < 26; i++) {
            positions[keyboard[i] - 'a'] = i;
        }

        int time = 0;
        int prevPos = 0;

        for (char c : word) {
            int curPos = positions[c - 'a'];
            time += abs(curPos - prevPos);
            prevPos = curPos;
        }

        cout << time << endl;
    }

    return 0;
}