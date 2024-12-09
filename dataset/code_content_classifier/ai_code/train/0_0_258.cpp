#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    string s;
    cin >> s;

    vector<vector<int>> A(p, vector<int>(p));
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            cin >> A[i][j];
        }
    }

    vector<bool> allowed(26, false); // assuming all lowercase Latin letters
    for (int i = 0; i < n; i++) {
        allowed[s[i] - 'a'] = true;
    }

    string result = "";
    for (int i = 0; i < n; i++) {
        if (i > 0 && !A[s[i] - 'a'][s[i - 1] - 'a']) {
            s[i] = '*'; // mark as removed
            if (i + 1 < n && !A[s[i] - 'a'][s[i + 1] - 'a']) {
                cout << 0 << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] != '*') {
            result += s[i];
        }
    }

    cout << result.length() << endl;

    return 0;
}