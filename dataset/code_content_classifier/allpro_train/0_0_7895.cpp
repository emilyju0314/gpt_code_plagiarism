#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<set<string>> substrings(n + 1);

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            string s = "";
            for (int j = i; j < i + len; j++) {
                s += (char)('a' + j);
            }
            random_shuffle(s.begin(), s.end());
            substrings[len].insert(s);
        }
    }

    set<string> allSubstrings;
    for (int len = 1; len <= n; len++) {
        allSubstrings.insert(substrings[len].begin(), substrings[len].end());
    }

    vector<string> guesses;
    for (int len = 1; len <= n; len++) {
        for (const string& s : substrings[len]) {
            guesses.push_back(s);
            if (guesses.size() == (n + 1) * (n + 1)) {
                break;
            }
        }
        if (guesses.size() == (n + 1) * (n + 1)) {
            break;
        }
    }

    random_shuffle(guesses.begin(), guesses.end());
    
    cout << "!";
    for (const string& s : guesses) {
        cout << s;
    }
    cout << endl;
    
    return 0;
}