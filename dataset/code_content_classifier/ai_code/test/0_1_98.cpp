#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string keyboard, word;
        cin.ignore();
        getline(cin, keyboard);
        getline(cin, word);

        vector<int> positions(26);
        for (int i = 0; i < 26; i++) {
            positions[keyboard[i] - 'a'] = i;
        }

        int time = 0;
        int current = 0;
        for (char c : word) {
            time += abs(positions[c - 'a'] - current);
            current = positions[c - 'a'];
        }

        cout << time << endl;
    }

    return 0;
}