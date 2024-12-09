#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    sort(s.begin(), s.end(), greater<char>());
    sort(t.begin(), t.end(), greater<char>());

    bool yaroslavWins = true;
    bool andreyWins = false;
    
    for (int i = 0; i < 2*n; i++) {
        if (s[i] >= t[i]) {
            andreyWins = true;
            yaroslavWins = false;
            break;
        } else if (s[i] < t[i]) {
            andreyWins = false;
            yaroslavWins = true;
            break;
        }
    }

    if (yaroslavWins && andreyWins) {
        cout << "Draw" << endl;
    } else if (yaroslavWins) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    return 0;
}