#include <iostream>
#include <string>
#include <set>

using namespace std;

bool checkRule(string p, string t, int l, int r) {
    int count = 0;
    for (int i = 0; i <= p.length() - t.length(); i++) {
        if (p.substr(i, t.length()) == t) {
            count++;
        }
    }
    return count >= l && count <= r;
}

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;

    set<string> goodSubstrings;

    for (int i = 0; i < n; i++) {
        string p;
        int l, r;
        cin >> p >> l >> r;

        for (int j = 1; j <= s.length(); j++) {
            for (int k = j; k <= s.length(); k++) {
                string t = s.substr(j - 1, k - j + 1);
                if (checkRule(p, t, l, r)) {
                    goodSubstrings.insert(t);
                }
            }
        }
    }

    cout << goodSubstrings.size() << endl;

    return 0;
}