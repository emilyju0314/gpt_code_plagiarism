#include <iostream>
#include <string>

using namespace std;

int occurrences(string s, string target) {
    int count = 0;
    size_t pos = 0;
    while ((pos = s.find(target, pos)) != string::npos) {
        count++;
        pos += target.length();
    }
    return count;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        string target = "abacaba";
        int cnt = occurrences(s, target);

        if (cnt > 1) {
            cout << "No" << endl;
        } else if (cnt == 1) {
            cout << "Yes" << endl;
            for (int i = 0; i < n; i++) {
                if (s[i] == '?') {
                    s[i] = 'd'; // replace '?' with a lowercase English letter
                }
            }
            cout << s << endl;
        } else {
            bool found = false;
            for (int i = 0; i <= n - 7; i++) {
                bool match = true;
                for (int j = 0; j < 7; j++) {
                    if (s[i+j] != target[j] && s[i+j] != '?') {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    string temp = s;
                    for (int j = 0; j < 7; j++) {
                        temp[i+j] = target[j];
                    }
                    if (occurrences(temp, target) == 1) {
                        s = temp;
                        found = true;
                        break;
                    }
                }
            }
            if (found) {
                cout << "Yes" << endl;
                for (int i = 0; i < n; i++) {
                    if (s[i] == '?') {
                        s[i] = 'd'; // replace '?' with a lowercase English letter
                    }
                }
                cout << s << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}