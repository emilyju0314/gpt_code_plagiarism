#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool canWin(const vector<string>& strings, int k) {
    unordered_set<string> possiblePrefixes(strings.begin(), strings.end());
    bool firstPlayer = true;

    while (true) {
        bool canMove = false;
        for (const string& prefix : possiblePrefixes) {
            for (char c = 'a'; c <= 'z'; c++) {
                string newPrefix = prefix + c;
                if (possiblePrefixes.count(newPrefix) == 0) {
                    canMove = true;
                    break;
                }
            }
            if (canMove) {
                break;
            }
        }

        if (!canMove || k == 0) {
            break;
        }

        k--;
        firstPlayer = !firstPlayer;

        unordered_set<string> newPossiblePrefixes;
        for (const string& prefix : possiblePrefixes) {
            for (const string& str : strings) {
                if (str.substr(0, prefix.length()) == prefix) {
                    newPossiblePrefixes.insert(str);
                }
            }
        }
        possiblePrefixes = move(newPossiblePrefixes);
    }

    return firstPlayer;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    if (canWin(strings, k)) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    return 0;
}