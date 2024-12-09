#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    int wins = 0;
    for (char c : S) {
        if (c == 'o') {
            wins++;
        }
    }

    if (wins + (15 - S.size()) >= 8) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}