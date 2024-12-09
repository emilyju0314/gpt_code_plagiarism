#include <iostream>
#include <string>

using namespace std;

bool isWinner(string s, int position) {
    string t = s.substr(0, position) + s.substr(position + 1);
    int n = t.size();
    for (int i = 1; i < n; i++) {
        if (i % 2 == 1) {
            bool symmetric = true;
            for (int j = 0; j <= i / 2; j++) {
                if (t[i / 2 - j] != t[i / 2 + j]) {
                    symmetric = false;
                    break;
                }
            }
            if (symmetric) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (isWinner(s, i)) {
            cout << "First" << endl;
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << "Second" << endl;

    return 0;
}